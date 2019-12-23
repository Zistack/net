struct T
{
	T ();

	template
	<
		typename InputStream,
		typename = std::enable_if_t <IO::IsInputStream::T <InputStream>::value>
	>
	T (InputStream && input_stream);

	T (const std::string & address_string);

	T (const std::array <uint8_t, 4> & octets);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream) const;

	std::string
	toString () const;

	~T () = default;

private:

	template <typename InputStream>
	void
	init (InputStream && input_stream);

	std::array <uint8_t, 4> m_octets;
};
