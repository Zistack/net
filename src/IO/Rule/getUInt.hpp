uint64_t
getUInt (Interface::PeekableInputStream::T & input_stream)
{
	std::string uint_string = Rule::getClass (input_stream, Class::digit);

	if (uint_string.empty ())
		throw Failure::SyntaxError::T ("Expected numeric value\n");

	return Util::toUInt (uint_string);
}
