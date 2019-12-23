struct T
{
	T ();

	template
	<
		typename InputStream,
		typename = std::enable_if_t <IO::IsInputStream::T <InputStream>::value>
	>
	T (InputStream && input_stream);

	T (const std::string & registered_name);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream) const;

	std::string
	toString () const;

	~T () = default;

private:

	std::string m_registered_name;
};
