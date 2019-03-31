template <typename InputStream>
uint64_t
getUInt (InputStream && input_stream)
{
	std::string uint_string = Rule::getClass
	(
		std::forward <InputStream> (input_stream),
		Class::digit
	);

	if (uint_string . empty ())
	{
		throw Failure::SyntaxError::T ("Expected numeric value\n");
	}

	return Util::toUInt (uint_string);
}
