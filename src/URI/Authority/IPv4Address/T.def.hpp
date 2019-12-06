T::T () : m_octets ({127, 0, 0, 1})
{
}

template <typename InputStream, typename>
T::T (InputStream && input_stream)
{
	this -> init (std::forward <InputStream> (input_stream));
}

T::T (const std::string & address_string)
{
	IO::String::Reader::T input_stream (address_string);
	this -> init (input_stream);
	IO::Util::expectEOF (input_stream);
}

T::T (const std::array <uint8_t, 4> & octets) : m_octets (octets)
{
}
