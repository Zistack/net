template <typename InputStream>
T::T (InputStream && input_stream)
{
	this -> init (std::forward <InputStream> (input_stream));
}

T::T (const std::string & number_string)
{
	IO::String::Reader::T input_stream (number_string);
	this -> init (input_stream);
	IO::Util::expectEOF (input_stream);
}
