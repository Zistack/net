struct T : MemberType::T
{
	using ValueType = std::string;

	T () = default;

	T (ValueType value);

	void
	readFrom (IO::Interface::PeekableInputStream::T & input_stream) override;

	void
	set (ValueType value);

	ValueType
	get () const;

	void
	writeTo (IO::Interface::OutputStream::T & output_stream) const override;

	~T () = default;

	private:
	std::string value;
};
