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

	const Array::T &
	asArray () const;

	Array::T &
	asArray ();

	bool
	isBoolean () const;

	const Boolean::T &
	asBoolean () const;

	Boolean::T &
	asBoolean ();

	bool
	isNumber () const;

	const Number::T &
	asNumber () const;

	Number::T &
	asNumber ();

	bool
	isObject () const;

	const Object::T &
	asObject () const;

	Object::T &
	asObject ();

	bool
	isString () const;

	const String::T &
	asString () const;

	String::T &
	asString ();

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
