void
T::init (IO::Interface::PeekableInputStream::T & input_stream)
{
	Parts::T parts (input_stream);

	if (parts.scheme)
	{
		this->scheme =
		    IO::Util::consume (parts.scheme.stdString (), Rule::getScheme);
	}

	if (parts.authority)
	{
		this->authority = Authority::T (parts.authority.stdString ());
	}

	this->path = Path::T (parts.path);

	if (parts.query)
	{
		this->query =
		    IO::Util::consume (parts.query.stdString (), Rule::getQuery);
	}

	if (parts.fragment)
	{
		this->fragment =
		    IO::Util::consume (parts.fragment.stdString (), Rule::getFragment);
	}
}
