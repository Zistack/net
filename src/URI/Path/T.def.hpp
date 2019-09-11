T::T () : m_absolute (true)
{
}

template <typename InputStream>
T::T (InputStream && input_stream)
{
	this -> init (std::forward <InputStream> (input_stream));
}

T::T (const std::string & path_string)
{
	IO::String::Reader::T input_stream (path_string);
	this -> init (input_stream);
	IO::Util::expectEOF (input_stream);
}

template <class Iterable, typename>
T::T (Iterable && iterable, bool absolute)
:	m_segments (iterable . begin (), iterable . end ()), m_absolute (absolute)
{
}
