std::pair <std::string, std::string>
getChunkExtension (
	IO::Interface::PeekableInputStream::T <char> * filtered_input_stream
)
{
	const std::string message_prefix = "HTTP::Rule::getChunkExtension\n";

	try
	{
		std::string field_name = getToken (filtered_input_stream);

		expect (filtered_input_stream, "=");

		std::string field_value;

		if (test (filtered_input_stream, '"'))
		{
			field_value = getQuotedString (filtered_input_stream);
		}
		else field_value = getToken (filtered_input_stream);

		return {field_name, field_value};
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
