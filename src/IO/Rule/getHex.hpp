uint64_t
getHex (Interface::PeekableInputStream::T & input_stream)
{
	std::string hex_string = getClass (input_stream, Class::hex);

	if (hex_string.empty ())
	{
		throw Failure::SyntaxError::T ("Expected hexadecimal value\n");
	}

	return Util::toNum (hex_string, 16);
}
