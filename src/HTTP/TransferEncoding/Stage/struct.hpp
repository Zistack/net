struct T
{
	virtual void
	recode (IO::Interface::InputStream::T & input_stream,
	    IO::Interface::OutputStream::T & output_stream) = 0;

	virtual ~T () = default;
};
