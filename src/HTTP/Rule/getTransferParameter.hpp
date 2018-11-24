std::pair<std::string, std::string>
getTransferParameter (IO::Interface::PeekableInputStream::T & input_stream)
{
	std::string parameter_name = getToken (input_stream);
	std::string parameter_value;

	IO::Util::expect (input_stream, '=');

	if (IO::Util::test (input_stream, '"'))
	{
		parameter_value = getQuotedString (input_stream);
	}
	else
	{
		parameter_value = getToken (input_stream);
	}

	return {parameter_name, parameter_value};
}
