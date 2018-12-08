struct T : TransferEncoding::T
{
	T (size_t chunk_size);

	void
	filter (
	    IO::Interface::InputStream::T & input_stream,
	    IO::Interface::OutputStream::T & output_stream) override;

	~T () = default;

	private:
	size_t chunk_size;
};
