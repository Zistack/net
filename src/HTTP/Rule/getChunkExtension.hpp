std::pair<std::string, NullableString::T>
getChunkExtension (IO::Interface::PeekableInputStream::T & input_stream)
{
	std::string field_name = getToken (input_stream);
	NullableString::T field_value;

	if (IO::Util::test (input_stream, '='))
	{
		if (IO::Util::test (input_stream, '"'))
		{
			field_value = getQuotedString (input_stream);
		}
		else
			field_value = getToken (input_stream);
	}
}

return {field_name, field_value};
}
