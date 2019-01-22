void
T::unloadCloseBuffer (FrameHeader::T & close_header,
    IO::Blocking::OutputStream::T & output_stream)
{
	std::unique_lock<decltype (this->close_mutex)> close_lock (
	    this->close_mutex);

	close_header.writeTo (output_stream);

	if (this->status_code != 1005)
	{
		IO::Rule::putIntType<decltype (this->status_code)> (
		    this->status_code, output_stream);
	}

	if (this->reason.has_value ())
	{
		Util::transfer (this->reason->inputStream (),
		    close_header.payload_length - sizeof (this->status_code),
		    close_header.masking_key,
		    output_stream);
		this->reason->reset ();
	}
}
