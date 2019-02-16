struct T : Member::Value::T
{
	using InterfaceType = std::string;

	T (const std::string & value);

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
	std::string value;
};
