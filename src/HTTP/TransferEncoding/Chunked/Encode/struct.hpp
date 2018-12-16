struct T : Stage::T
{
	T (size_t chunk_size);

	void
	recode (IO::Interface::InputStream::T & input_stream,
	    IO::Interface::OutputStream::T & output_stream) override;

	~T () = default;

	private:
	size_t chunk_size;
};
