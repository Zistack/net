struct T : Stage::T
{
	T (size_t count);

	void
	recode (IO::Interface::InputStream::T & input_stream,
	    IO::Interface::OutputStream::T & output_stream) override;

	~T () = default;

	private:
	size_t count;
};
