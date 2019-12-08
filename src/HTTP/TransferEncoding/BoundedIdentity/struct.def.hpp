struct T
{
	T (size_t count);

	template <typename InputStream, typename OutputStream>
	void
	recode (InputStream && input_stream, OutputStream && output_stream) const;

	~T () = default;

private:

	size_t m_count;
};
