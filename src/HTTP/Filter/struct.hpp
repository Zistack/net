struct T : IO::Interface::InputStream::T <char>
{
	T (IO::Interface::PeekableInputStream::T <char> * input_stream);

	char get () override;

	~T () = default;

	IO::Interface::PeekableInputStream::T <char> * input_stream;
};
