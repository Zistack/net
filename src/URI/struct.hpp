struct T
{
	T (IO::Interface::PeekableInputStream::T & input_stream);

	T (const std::string & uri_string);

	T (const NullableString::T & scheme,
	    const std::optional<Authority::T> & authority,
	    const Path::T & path,
	    const NullableString::T & query,
	    const NullableString::T & fragment);

	std::string
	toString () const;

	~T ();

	private:
	void
	init (IO::Interface::PeekableInputStream::T & input_stream);

	NullableString::T scheme;
	std::optional<Authority::T> authority;
	Path::T path;
	NullableString::T query;
	NullableString::T fragment;
};
