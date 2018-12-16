struct T : Stage::T
{
	T () = default;

	T (const Options::T & options);

	void
	recode (IO::Interface::InputStream::T & input_stream,
	    IO::Interface::OutputStream::T & output_stream) override;

	~T () = default;
};
