struct T
{
	T (IO::Interface::PeekableInputStream::T <char> * input_stream);

	void
	writeTo (IO::Interface::OutputStream::T <char> * output_stream);

	~T () = default;

	std::string name;
	std::list <std::string> parameters;
};
