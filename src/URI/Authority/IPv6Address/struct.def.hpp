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

	T (const std::array <uint16_t, 8> & hexadecitets);

	int
	compare (const T & other) const;

	bool
	operator == (const T & other) const;

	bool
	operator != (const T & other) const;

	bool
	operator < (const T & other) const;

	bool
	operator > (const T & other) const;

	bool
	operator <= (const T & other) const;

	bool
	operator >= (const T & other) const;

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

	template <typename InputStream>
	static std::vector <uint16_t>
	getHead (InputStream && input_stream);

	template <typename InputStream>
	static std::vector <uint16_t>
	getTail (InputStream && input_stream);

	static std::string
	hexadecitetToString (uint16_t hexadecitet);

	std::array <uint16_t, 8> m_hexadecitets;
};
