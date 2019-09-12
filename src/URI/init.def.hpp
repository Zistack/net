template <typename InputStream>
void
T::init (InputStream && input_stream)
{
	Parts::T parts (std::forward <InputStream> (input_stream));

	if (parts . scheme)
	{
		IO::String::Reader::T input_stream (* parts . scheme);
		this -> scheme = Rule::getScheme (input_stream);
		IO::Util::expectEOF (input_stream);
	}

	if (parts . authority)
	{
		this -> authority = Authority::T (* parts . authority);
	}

	this -> path = Path::T (parts . path);

	if (parts . query)
	{
		IO::String::Reader::T input_stream (* parts . query);
		this -> query = Rule::getQuery (input_stream);
		IO::Util::expectEOF (input_stream);
	}

	if (parts . fragment)
	{
		IO::String::Reader::T input_stream (* parts . fragment);
		this -> fragment = Rule::getFragment (input_stream);
		IO::Util::expectEOF (input_stream);
	}
}
