struct T : Value::T
{
	T (IO::Interface::PeekableInputStream::T * input_stream);
	T (std::string number);

	void
	writeTo (OutputStream::T * json_output_stream) override;

	~T () override;

	void
	init (IO::Interface::PeekableInputStream::T * input_stream);

	std::string * base;
	std::string * mantissa;
	std::string * exponent;
};
