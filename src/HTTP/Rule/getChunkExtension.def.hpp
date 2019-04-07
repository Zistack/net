template <typename InputStream>
std::pair<std::string, NullableString::T>
getChunkExtension (InputStream && input_stream)
{
	std::string field_name = getToken
	(
		std::forward <InputStream> (input_stream)
	);
	NullableString::T field_value;

	if (IO::Util::test (std::forward <InputStream> (input_stream), '='))
	{
		if (IO::Util::test (std::forward <InputStream> (input_stream), '"'))
		{
			field_value = getQuotedString
			(
				std::forward <InputStream> (input_stream)
			);
		}
		else
		{
			field_value = getToken (std::forward <InputStream> (input_stream));
		}
	}

	return {field_name, field_value};
}
