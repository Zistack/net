uint64_t
getNum (Interface::PeekableInputStream::T & input_stream)
{
	std::string num_string = Rule::getClass (input_stream, Class::digit);

	if (num_string.empty ())
		throw Failure::SyntaxError::T ("Expected numeric value\n");

	return Util::toUInt (num_string);
}
