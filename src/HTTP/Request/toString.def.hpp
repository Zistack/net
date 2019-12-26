std::string
T::toString () const
{
	std::string request_string;
	IO::String::Writer::T output_stream (request_string);
	this -> writeTo (output_stream);

	return request_string;
}
