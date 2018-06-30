struct T
{
	T (IO::Interface::PeekableInputStream::T <char> * input_stream);

	T (std::string);

	void
	writeTo (IO::Interface::OutputStream::T <char> * output_stream);

	~T ();

	void
	init (IO::Interface::PeekableInputStream::T <char> * input_stream);

	std::string * base;
	std::string * mantissa;
	std::string * exponent;
};
