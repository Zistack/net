struct T
{
	T (size_t chunk_size);

	template <typename InputStream, typename OutputStream>
	void
	recode (InputStream && input_stream, OutputStream && output_stream);

	~T () = default;

private:

	size_t m_chunk_size;
};
