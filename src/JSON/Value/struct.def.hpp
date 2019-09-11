struct T
{
	T () = default;

	template <typename InputStream>
	T (InputStream && input_stream);

	// What do we do about constructing specific types of JSON values?

	bool
	isNull () const;

	bool
	isArray () const;

	bool
	isBoolean () const;

	bool
	isNumber () const;

	bool
	isObject () const;

	bool
	isString () const;

	// IDK how I want to handle pretty-printing.
	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation = 0);

	virtual ~T () = default;

private:

	std::variant
	<
		Null::T,
		Array::T,
		Boolean::T,
		Number::T,
		Object::T,
		String::T
	> m_contents;
};
