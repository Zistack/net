template <typename Protocol, typename Dispatcher>
template <typename InputStream>
void
T <Protocol, Dispatcher>::processEvent (InputStream && input_stream)
{
	InputEntitySlot::T entity_slot;
	Failure::CancellableAggregate::T cancel_handle (input_stream, entity_slot);

	try
	{
		{
			Thread::Timer::T input_timer
			(
				this -> m_input_timeout,
				& decltype (cancel_handle)::cancel,
				& cancel_handle
			);

			FrameHeader::T frame_header
			(
				std::forward <InputStream> (input_stream)
			);

			try
			{
				frame_header . validate ((bool) this -> m_message);
			}
			catch (const Failure::SemanticError::T & e)
			{
				this -> m_exception_store . store (std::current_exception ());

				this -> cancel ();
				this -> output () . cancel (CloseMessage::T (1002, e . what ()));

				Util::discard
				(
					std::forward <InputStream> (input_stream),
					frame_header . payload_length
				);

				return;
			}

			if (frame_header . opcode == Type::PING)
			{
				this -> readPing
				(
					frame_header,
					std::forward <InputStream> (input_stream)
				);
			}
			else if (frame_header . opcode == Type::PONG)
			{
				this -> readPong
				(
					frame_header,
					std::forward <InputStream> (input_stream)
				);
			}
			else if (frame_header . isMessage ())
			{
				this -> readMessage
				(
					frame_header,
					std::forward <InputStream> (input_stream),
					entity_slot
				);
			}
			else if (frame_header . opcode == Type::CONTINUATION)
			{
				this -> readContinuation
				(
					frame_header,
					std::forward <InputStream> (input_stream),
					entity_slot
				);
			}
			else if (frame_header.opcode == Type::CLOSE)
			{
				this -> readClose
				(
					frame_header,
					std::forward <InputStream> (input_stream)
				);
			}
		}
		if constexpr (IO::TypeTraits::IsClearable::T <InputStream>::value)
		{
			input_stream . clear ();
		}
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Reading frame timed out\n");
	}
}
