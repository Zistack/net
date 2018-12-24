T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	uint64_t first = IO::Rule::getNum (input_stream);

	if (first > 255)
	{
		throw Failure::SyntaxError::T ("IPv4 octet must be less than 256\n");
	}

	IO::Util::expect (input_stream, '.');
	uint64_t second = IO::Rule::getNum (input_stream);

	if (second > 255)
	{
		throw Failure::SyntaxError::T ("IPv4 octet must be less than 256\n");
	}

	IO::Util::expect (input_stream, '.');
	uint64_t third = IO::Rule::getNum (input_stream);

	if (third > 255)
	{
		throw Failure::SyntaxError::T ("IPv4 octet must be less than 256\n");
	}

	IO::Util::expect (input_stream, '.');
	uint64_t fourth = IO::Rule::getNum (input_stream);

	if (fourth > 255)
	{
		throw Failure::SyntaxError::T ("IPv4 octet must be less than 256\n");
	}

	this->octets = {
	    (uint8_t) first, (uint8_t) second, (uint8_t) third, (uint8_t) fourth};
}

T::T (const std::array<uint8_t, 4> & octets) : octets (octets) {}
