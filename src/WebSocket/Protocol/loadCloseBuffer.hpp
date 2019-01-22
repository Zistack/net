void
T::loadCloseBuffer (FrameHeader::T & close_header,
    IO::Blocking::InputStream::T & input_stream)
{
	std::unique_lock<decltype (this->close_mutex)> close_lock (
	    this->close_mutex);

	if (close_header.payload_length >= sizeof (this->status_code))
	{
		this->status_code =
		    IO::Rule::getIntType<decltype (this->status_code)> (input_stream);

		if (close_header.payload_length - sizeof (this->status_code) > 0)
		{
			this->reason.emplace ();
			Util::transfer (input_stream,
			    close_header.payload_length - sizeof (this->status_code),
			    close_header.masking_key,
			    this->reason->outputStream ());
			this->reason->reset ();
		}
	}
	else if (close_header.payload_length == 0)
	{
		this->status_code = 1005;
	}
	else
	{
		throw Failure::SemanticError::T (
		    "Nonzero payloads on close frames must be at least " +
		    std::to_string (sizeof (this->status_code)) + " bytes long\n");
	}
}
