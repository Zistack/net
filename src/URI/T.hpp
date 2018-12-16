T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	init (input_stream);
}

T::T (const std::string & uri_string)
{
	IO::Util::consume (uri_string,
	    [this](IO::Interface::PeekableInputStream::T & input_stream) {
		    this->init (input_stream);
	    });
}

T::T (const NullableString::T & scheme,
    const std::optional<Authority::T> & authority,
    const Path::T & path,
    const NullableString::T & query,
    const NullableString::T & fragment) :
    scheme (scheme),
    authority (authority),
    path (path),
    query (query),
    fragment (fragment)
{
}
