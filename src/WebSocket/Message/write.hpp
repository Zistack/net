void
T::write (uint64_t chunk_size,
    std::array<uint8_t, 4> masking_key,
    IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & timeout_signal)
{
	if (this->body->isNonblocking ())
	{
		IO::Blocking::InputStream::T input_stream (
		    this->body->asNonblocking ().inputStream (), timeout_signal);

		Util::transfer (input_stream, chunk_size, masking_key, output_stream);
	}
	else if (this->body->isBlocking ())
	{
		Util::transfer (this->body->asBlocking ().inputStream (),
		    chunk_size,
		    masking_key,
		    output_stream);
	}
}
