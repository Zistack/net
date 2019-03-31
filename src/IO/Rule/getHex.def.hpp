template <typename InputStream>
uint64_t
getHex (InputStream && input_stream)
{
	std::string hex_string = getClass
	(
		std::forward <InputStream> (input_stream),
		Class::hex
	);

	if (hex_string . empty ())
	{
		throw Failure::SyntaxError::T ("Expected hexadecimal value\n");
	}

	return Util::toUInt (hex_string, 16);
}
