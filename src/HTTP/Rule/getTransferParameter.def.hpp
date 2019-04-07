template <typename InputStream>
std::pair <std::string, std::string>
getTransferParameter (InputStream && input_stream)
{
	std::string parameter_name = getToken
	(
		std::forward <InputStream> (input_stream)
	);
	std::string parameter_value;

	IO::Util::expect (std::forward <InputStream> (input_stream), '=');

	if (IO::Util::test (std::forward <InputStream> (input_stream), '"'))
	{
		parameter_value = getQuotedString
		(
			std::forward <InputStream> (input_stream)
		);
	}
	else
	{
		parameter_value = getToken (std::forward <InputStream> (input_stream));
	}

	return {parameter_name, parameter_value};
}
