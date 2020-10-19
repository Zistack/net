struct T
{
	T () = default;

	template <typename InputStream>
	T (InputStream && input_stream);

	// We'll want a constructor that lets us set the contents to something
	// interesting.

	bool
	contains (const std::string & name) const;

	const Value::T &
	valueAt (const std::string & name) const;

	Value::T &
	valueAt (const std::string & name);

	const Array::T &
	arrayAt (const std::string & name) const;

	Array::T &
	arrayAt (const std::string & name);

	const Boolean::T &
	booleanAt (const std::string & name) const;

	Boolean::T &
	booleanAt (const std::string & name);

	const Number::T &
	numberAt (const std::string & name) const;

	Number::T &
	numberAt (const std::string & name);

	const Object::T &
	objectAt (const std::string & name) const;

	Object::T &
	objectAt (const std::string & name);

	const String::T &
	stringAt (const std::string & name) const;

	String::T &
	stringAt (const std::string & name);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation = 0) const;

	~T () = default;

private:

	std::unordered_map <std::string, std::unique_ptr <Value::T>> m_members;
};
