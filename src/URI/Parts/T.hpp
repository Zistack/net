T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	std::string first_part = getFirstPart (input_stream);

	if (IO::Util::test (input_stream, ':'))
	{
		this->scheme = first_part;

		input_stream.get ();

		if (IO::Util::test (input_stream, '/'))
		{
			input_stream.get ();

			if (IO::Util::test (input_stream, '/'))
			{
				input_stream.get ();
				this->authority = getAuthorityPart (input_stream);
			}
			else
			{
				this->path.push_back ('/');
			}

			this->path.append (getPathPart (input_stream));
		}
	}
	else
	{
		this->path = first_part;
		this->path.append (getPathPart (input_stream));
	}

	if (IO::Util::test (input_stream, '?'))
	{
		input_stream.get ();
		this->query = getQueryPart (input_stream);
	}

	if (IO::Util::test (input_stream, '#'))
	{
		this->fragment = getFragmentPart (input_stream);
	}
}

T::T (const std::string & uri_string) :
    T (IO::String::T (uri_string).peekableInputStream ())
{
}
