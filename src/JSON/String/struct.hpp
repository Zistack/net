struct T : Value::T
{
	T (IO::Interface::PeekableInputStream::T & input_stream);
	T (const std::string & string);

	void
	writeTo (IO::Interface::OutputStream::T & output_stream,
	    size_t indentation = 0) override;

	T &
	asString () override;

	std::string &
	value ();

	const std::string &
	value () const;

	operator const std::string & () const;

	~T () override = default;

	private:
	std::string string;
};
