void
T::append (IO::Interface::InputStream::T & input_stream,
    uint64_t chunk_size,
    std::array<uint8_t, 4> masking_key,
    IO::CancelSignal::T & timeout_signal)
{
	if (this->body->isNonblocking ())
	{
		IO::Blocking::OutputStream::T output_stream (
		    this->body->asNonblocking ().outputStream (), timeout_signal);

		Util::transfer (input_stream, chunk_size, masking_key, output_stream);
	}
	else if (this->body->isBlocking ())
	{
		Util::transfer (input_stream,
		    chunk_size,
		    masking_key,
		    this->body->asBlocking ().outputStream ());
	}
}
