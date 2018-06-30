struct T
{
	T (IO::Interface::OutputStream::T <char> * output_stream);

	void
	putArray (std::function <bool ()> isValue, std::function <void ()> putValue);

	void
	putBool (bool b);

//	void
//	putNumber (Number::T number);

	void
	putObject (std::unordered_map <std::string, std::function <void ()>> member_putters);

	void
	putString (std::string string);

	~T () = default;

	void
	indent ();

	void
	open (char c);

	void
	clse (char c);

	unsigned int indentation;

	IO::Interface::OutputStream::T <char> * output_stream;
};
