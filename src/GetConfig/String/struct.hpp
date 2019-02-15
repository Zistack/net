struct T : MemberType::T
{
	using ValueType = Value::T;

	std::unique_ptr<MemberType::T>
	clone () const override;

	std::unique_ptr<MemberValue::T>
	readFrom (
	    IO::Interface::PeekableInputStream::T & input_stream) const override;

	void
	writeTo (const MemberValue::T & member,
	    IO::Interface::OutputStream::T & output_stream,
	    size_t indentation) const override;

	std::unique_ptr<ValueType>
	set (const ValueType::InterfaceType & value) const;

	const ValueType::InterfaceType &
	get (const ValueType & value) const;
};
