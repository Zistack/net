struct T : Member::Value::T
{
	using InterfaceType = uint64_t;

	T (const InterfaceType & value);

	T (IO::Interface::PeekableInputStream::T & input_stream);

	std::unique_ptr<Member::Value::T>
	clone () const override;

	const InterfaceType &
	get () const;

	void
	writeTo (IO::Interface::OutputStream::T & output_stream,
	    size_t indentation) const;

	~T () = default;

	private:
	uint64_t value;
};
