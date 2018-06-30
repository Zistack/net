std::pair <std::string, std::string>
getHeader (IO::Interface::PeekableInputStream::T <char> * filtered_input_stream)
{
	const std::string message_prefix = "HTTP::Rule::getHeader\n";

	try
	{
		std::string field_name = getToken (filtered_input_stream);

		IO::Util::expect (filtered_input_stream, ':');

		std::string field_value = getHeaderField (filtered_input_stream);
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
