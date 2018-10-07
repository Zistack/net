struct T : Value::T
{
	T (IO::Interface::PeekableInputStream::T * input_stream);
	T (std::string number);

	void
	writeTo (IO::Interface::OutputStream::T * output_stream,
	    size_t indentation = 0) override;

	T *
	asNumber () override;

	~T () override;

	void
	init (IO::Interface::PeekableInputStream::T * input_stream);

	std::string * base;
	std::string * mantissa;
	std::string * exponent;
};
