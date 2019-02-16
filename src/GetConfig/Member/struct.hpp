struct T
{
	// using ValueType = Value::T;

	virtual std::unique_ptr<T>
	clone () const = 0;

	virtual std::unique_ptr<Value::T>
	readFrom (IO::Interface::PeekableInputStream::T & input_stream) const = 0;

	virtual void
	validate (const Value::T & value) const = 0;

	virtual void
	writeTo (const Value::T & value,
	    IO::Interface::OutputStream::T & output_stream,
	    size_t indentation) const = 0;

	// std::unique_ptr <ValueType> set (const ValueType::InterfaceType & value)
	// const;

	// const ValueType::InterfaceType & get (const ValueType & value) const;
};
