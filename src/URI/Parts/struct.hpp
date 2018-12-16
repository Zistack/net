struct T
{
	T (IO::Interface::PeekableInputStream::T & input_stream);

	T (const std::string & path_string);

	~T () = default;

	NullableString::T scheme;
	NullableString::T authority;
	std::string path;
	NullableString::T query;
	NullableString::T fragment;

	private:
	static std::string
	getFirstPart (IO::Interface::PeekableInputStream::T & input_stream);

	static std::string
	getAuthorityPart (IO::Interface::PeekableInputStream::T & input_stream);

	static std::string
	getPathPart (IO::Interface::PeekableInputStream::T & input_stream);

	static std::string
	getQueryPart (IO::Interface::PeekableInputStream::T & input_stream);

	static std::string
	getFragmentPart (IO::Interface::PeekableInputStream::T & input_stream);
};
