template <typename InputStream, typename>
T::T (InputStream && input_stream)
{
	this -> init (std::forward <InputStream> (input_stream));
}

T::T (const std::string & uri_string)
{
	IO::String::Reader::T input_stream (uri_string);
	this -> init (input_stream);
}
