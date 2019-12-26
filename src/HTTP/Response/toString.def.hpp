std::string
T::toString () const
{
	std::string response_string;
	IO::String::Writer::T output_stream (response_string);
	this -> writeTo (output_stream);

	return response_string;
}
