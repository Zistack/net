struct T
{
	template <typename InputStream>
	T (InputStream && input_stream);

	T (const std::string & string);

	std::string &
	value ();

	const std::string &
	value () const;

	operator const std::string & () const;

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation = 0) const;

	~T () = default;

private:

	std::string string;
};
