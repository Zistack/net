struct T
{
	template <typename InputStream>
	T (InputStream && input_stream);

	T
	(
		const std::string & name,
		const std::optional <std::string> & version = std::nullopt
	);

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

	std::string
	toString () const;

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream);

	~T () = default;

	std::string name;
	std::optional <std::string> version;
};
