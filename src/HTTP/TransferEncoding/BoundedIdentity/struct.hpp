struct T : TransferEncoding::T
{
	T (size_t count);

	void
	filter (
	    IO::Interface::InputStream::T & input_stream,
	    IO::Interface::OutputStream::T & output_stream) override;

	~T () = default;

	private:
	size_t count;
};
