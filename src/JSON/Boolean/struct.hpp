struct T : Value::T
{
	T (IO::Interface::PeekableInputStream::T & input_stream);
	T (bool value);

	void
	writeTo (IO::Interface::OutputStream::T & output_stream,
	    size_t indentation = 0) override;

	T &
	asBoolean () override;

	bool
	value () const;

	operator bool () const;

	~T () override = default;

	private:
	bool b;
};
