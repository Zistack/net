struct T : Member::T
{
	using ValueType = Value::T;

	T (const Spec::T & spec);

	std::unique_ptr<Member::T>
	clone () const override;

	std::unique_ptr<Member::Value::T>
	readFrom (
	    IO::Interface::PeekableInputStream::T & input_stream) const override;

	void
	validate (const Member::Value::T & value) const override;

	void
	writeTo (const Member::Value::T & value,
	    IO::Interface::OutputStream::T & output_stream,
	    size_t indentation) const override;

	std::unique_ptr<ValueType>
	set (const ValueType::InterfaceType & value) const;

	const ValueType::InterfaceType &
	get (const ValueType & value) const;

	~T () = default;

	private:
	const Spec::T & spec;
};
