void
T::append (Masking::InputStream::T & input_stream,
    uint64_t chunk_size,
    IO::CancelSignal::T & timeout_signal)
{
	if (this->body->isNonblocking ())
	{
		IO::Blocking::OutputStream::T output_stream (
		    this->body->asNonblocking ().outputStream (), timeout_signal);

		Util::transfer (input_stream, chunk_size, output_stream);
	}
	else if (this->body->isBlocking ())
	{
		Util::transfer (input_stream,
		    chunk_size,
		    this->body->asBlocking ().outputStream ());
	}
}
