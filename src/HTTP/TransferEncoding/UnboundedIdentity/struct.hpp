struct T : TransferEncoding::T
{
	T () = default;

	T (const Options::T & options);

	void
	filter (IO::Interface::InputStream::T & input_stream,
	    IO::Interface::OutputStream::T & output_stream) override;

	~T () = default;
};
