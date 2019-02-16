struct T : Member::T
{
	using ValueType = Value::T;

	std::unique_ptr<Member::T>
	clone () const override;

	std::unique_ptr<Member::Value::T>
	readFrom (
	    IO::Interface::PeekableInputStream::T & input_stream) const override;

	void
	writeTo (const Member::Value::T & member,
	    IO::Interface::OutputStream::T & output_stream,
	    size_t indentation) const override;

	std::unique_ptr<ValueType>
	set (const ValueType::InterfaceType & value) const;

	const ValueType::InterfaceType &
	get (const ValueType & value) const;
};
