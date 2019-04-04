T::T () : hexadecitets ({0, 0, 0, 0, 0, 0, 0, 1})
{
}

template <typename InputStream>
T::T (InputStream && input_stream) : hexadecitets ({0})
{
	this->init (std::forward <InputStream> (input_stream));
}

T::T (const std::string & address_string) : hexadecitets ({0})
{
	IO::String::Reader::T input_stream (address_string);
	this -> init (input_stream);
	IO::Util::expectEOF (input_stream);
}

T::T (const std::array <uint16_t, 8> & hexadecitets)
:	hexadecitets (hexadecitets)
{
}