struct T
{
	T (IO::Interface::PeekableInputStream::T & input_stream);

	~T () = default;

	std::string identifier;
	std::unordered_map<std::string, NullableString::T> options;
};
