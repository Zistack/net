struct T
{
	virtual void
	filter (IO::Interface::InputStream::T & input_stream,
	    IO::Interface::OutputStream::T & output_stream) = 0;
};
