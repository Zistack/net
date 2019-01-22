void
T::processEvent (IO::Blocking::InputStream::T & input_stream,
    IO::CancelSignal::T & input_timeout_signal)
{
	// I might want to move some of the validation to _after_ we read in the
	// payload, so that there's a chance that I could send and recieve a close
	// frame later.

	FrameHeader::T frame_header;
	IO::Vector::T pong_payload;

	try
	{
		{
			Thread::Timer::T input_timer (this->input_timeout,
			    &IO::CancelSignal::T::cancel,
			    &input_timeout_signal);

			frame_header = FrameHeader::T (input_stream);

			if (frame_header.opcode == Type::PING)
			{
				if (frame_header.payload_length > 125)
				{
					throw Failure::SemanticError::T (
					    "Control frames may not have a payload of more than "
					    "125 bytes\n");
				}

				if (!frame_header.final_frame)
				{
					throw Failure::SemanticError::T (
					    "Control frames may not have fragmented payloads\n");
				}

				std::vector<uint8_t> payload;
				decltype (payload)::size_type pointer;
				IO::Vector::OutputStream::T output_stream (payload, pointer);

				Util::transfer (input_stream,
				    frame_header.payload_length,
				    frame_header.masking_key,
				    output_stream);

				this->ping_pong_sender.pong (payload);
			}
			else if (frame_header.opcode == Type::PONG)
			{
				if (frame_header.payload_length > 125)
				{
					throw Failure::SemanticError::T (
					    "Control frames may not have a payload of more than "
					    "125 bytes\n");
				}

				if (!frame_header.final_frame)
				{
					throw Failure::SemanticError::T (
					    "Control frames may not have fragmented payloads\n");
				}

				Util::transfer (input_stream,
				    frame_header.payload_length,
				    frame_header.masking_key,
				    pong_payload.outputStream ());

				goto pong;
			}
			else if (frame_header.opcode == Type::TEXT ||
			    frame_header.opcode == Type::BINARY)
			{
				if (this->message)
				{
					throw Failure::SemanticError::T (
					    "Must finish previous message before starting a new "
					    "one\n");
				}

				this->message.reset (new Message::T (frame_header.opcode,
				    this->pickEntity (frame_header.final_frame,
				        frame_header.payload_length)));

				this->message->append (input_stream,
				    frame_header.payload_length,
				    frame_header.masking_key,
				    input_timeout_signal);

				goto message;
			}
			else if (frame_header.opcode == Type::CONTINUATION)
			{
				if (!this->message)
				{
					throw Failure::SemanticError::T (
					    "Must start a message before continuing one\n");
				}

				this->message->append (input_stream,
				    frame_header.payload_length,
				    frame_header.masking_key,
				    input_timeout_signal);

				goto message;
			}
			else if (frame_header.opcode == Type::CLOSE)
			{
				if (frame_header.payload_length > 125)
				{
					throw Failure::SemanticError::T (
					    "Control frames may not have a payload of more than "
					    "125 bytes\n");
				}

				if (!frame_header.final_frame)
				{
					throw Failure::SemanticError::T (
					    "Control frames may not have fragmented payloads\n");
				}

				this->loadCloseBuffer (frame_header, input_stream);

				throw Failure::EndOfResource::T ();
			}
			else
			{
				throw Failure::SemanticError::T (
				    "Cannot interpret unknown opcode\n");
			}
		}
		input_timeout_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Reading frame timed out\n");
	}

pong:

	pong_payload.reset ();

	this->dispatcher.pong (*this, pong_payload);

	return;

message:

	if (frame_header.final_frame)
	{
		this->message->finish ();

		this->dispatcher.dispatch (*this, *this->message);
		this->message.reset ();
	}

	return;
}
