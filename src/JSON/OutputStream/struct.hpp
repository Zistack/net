struct T
{
	T (IO::Interface::OutputStream::T * output_stream);

	void
	put (Value::T * json_value);

	~T () = default;

	void
	open (char c);

	void
	close (char c);

	void
	put (char c);

	void
	print (std::string string);

	void
	indent ();

	unsigned int indentation;

	IO::Interface::OutputStream::T * output_stream;
};
