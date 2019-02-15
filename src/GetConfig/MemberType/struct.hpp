struct T
{
	// using ValueType = Value::T;

	virtual std::unique_ptr<T>
	clone () const = 0;

	virtual std::unique_ptr<MemberValue::T>
	readFrom (IO::Interface::PeekableInputStream::T & input_stream) const = 0;

	virtual void
	writeTo (const MemberValue::T &,
	    IO::Interface::OutputStream::T & output_stream,
	    size_t indentation) const = 0;

	// std::unique_ptr <ValueType> set (ValueType::InterfaceType value) const;

	// ValueType::InterfaceType get (ValueType) const;
};
