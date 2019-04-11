struct T
{
	template <typename InputStream>
	T (InputStream && input_stream);

	T (bool value);

	bool
	value () const;

	operator bool () const;

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation = 0) const;

	~T () = default;

private:

	bool b;
};
