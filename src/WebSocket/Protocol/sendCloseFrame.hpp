void
T::sendCloseFrame (IO::Blocking::OutputStream::T & output_stream,
    IO::CancelSignal::T & output_timeout_signal)
{
	FrameHeader::T close_header (
	    true, false, false, false, Type::CLOSE, 0, {0});

	if (this->status_code >= 1000)
	{
		if (this->status_code == 1005)
		{
			this->unloadCloseBuffer (close_header, output_stream);
		}
		else
		{
			close_header.payload_length =
			    sizeof (this->status_code) + (uint64_t) this->reason->size ();

			this->unloadCloseBuffer (close_header, output_stream);
		}
	}
	else if (this->exception_store)
	{
		try
		{
			this->exception_store.poll ();
		}
		catch (const Failure::ResourceError::T & e)
		{
			uint16_t status_code = 1011;
			std::string reason = e.what ();
			close_header.payload_length = sizeof (status_code) + reason.size ();

			close_header.writeTo (output_stream);
			IO::Rule::putIntType<decltype (status_code)> (
			    status_code, output_stream);
			output_stream.print (reason);
		}
		catch (const Failure::SemanticError::T & e)
		{
			uint16_t status_code = 1002;
			std::string reason = e.what ();
			close_header.payload_length = sizeof (status_code) + reason.size ();

			close_header.writeTo (output_stream);
			IO::Rule::putIntType<decltype (status_code)> (
			    status_code, output_stream);
			output_stream.print (reason);
		}
	}
	else
	{
		uint16_t status_code = 1000;
		close_header.payload_length = sizeof (status_code);

		close_header.writeTo (output_stream);
		IO::Rule::putIntType<decltype (status_code)> (
		    status_code, output_stream);
	}
}
