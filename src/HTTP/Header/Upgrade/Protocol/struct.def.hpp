struct T
{
	template <typename InputStream>
	T (InputStream && input_stream);

	T (const std::string & name, const NullableString::T & version = nullptr);

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
	writeTo (OutputStream && output_stream);

	~T () = default;

	std::string m_name;
	NullableString::T m_version;
};
