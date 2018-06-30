struct T
{
	T (IO::Interface::PeekableInputStream::T <char> * input_stream);

	void
	getArray (std::function <void ()> getValue);

	bool
	getBool ();

//	Number::T
//	getNumber ();

	void
	getObject (std::unordered_map <std::string, std::function<void ()>> member_getters);

	std::string
	getString ();

	~T () = default;

	IO::Interface::PeekableInputStream::T <char> * input_stream;
};
