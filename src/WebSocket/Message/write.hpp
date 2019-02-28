void
T::write (uint64_t chunk_size,
    Masking::OutputStream::T & output_stream,
    IO::CancelSignal::T & timeout_signal)
{
	if (this->body->isNonblocking ())
	{
		IO::Blocking::InputStream::T input_stream (
		    this->body->asNonblocking ().inputStream (), timeout_signal);

		Util::transfer (input_stream, chunk_size, output_stream);
	}
	else if (this->body->isBlocking ())
	{
		Util::transfer (this->body->asBlocking ().inputStream (),
		    chunk_size,
		    output_stream);
	}
}
