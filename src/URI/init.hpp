void
T::init (IO::Interface::PeekableInputStream::T & input_stream)
{
	Parts::T parts (input_stream);

	if (parts.scheme)
	{
		this->scheme = IO::Util::consume (parts.scheme, Rule::getScheme);
	}

	if (parts.authority)
	{
		this->authority = Authority::T (parts.authority);
	}

	this->path = Path::T (parts.path);

	if (parts.query)
	{
		this->query = IO::Util::consume (parts.query, Rule::getQuery);
	}

	if (parts.fragment)
	{
		this->fragment = IO::Util::consume (parts.fragment, Rule::getFragment);
	}
}
