template <typename TypeType, typename ValueType>
struct T : Type::T
{
	std::unique_ptr<Type::T>
	clone () const override;

	std::unique_ptr<Value::T>
	readFrom (
	    IO::Interface::PeekableInputStream::T & input_stream) const override;

	void
	validate (const Value::T & value) const override;

	void
	writeTo (const Value::T & value,
	    IO::Interface::OutputStream::T & output_stream,
	    size_t indentation) const override;

	std::unique_ptr<ValueType>
	set (const typename ValueType::InterfaceType & value) const;

	const typename ValueType::InterfaceType &
	get (const ValueType & value) const;
};
