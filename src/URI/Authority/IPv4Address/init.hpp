template <typename InputStream>
void
T::init (InputStream && input_stream)
{
	uint64_t first =
	    IO::Rule::getUInt (std::forward<InputStream> (input_stream));

	if (first > 255)
	{
		throw Failure::SyntaxError::T ("IPv4 octet must be less than 256\n");
	}

	IO::Util::expect (std::forward<InputStream> (input_stream), '.');
	uint64_t second =
	    IO::Rule::getUInt (std::forward<InputStream> (input_stream));

	if (second > 255)
	{
		throw Failure::SyntaxError::T ("IPv4 octet must be less than 256\n");
	}

	IO::Util::expect (std::forward<InputStream> (input_stream), '.');
	uint64_t third =
	    IO::Rule::getUInt (std::forward<InputStream> (input_stream));

	if (third > 255)
	{
		throw Failure::SyntaxError::T ("IPv4 octet must be less than 256\n");
	}

	IO::Util::expect (std::forward<InputStream> (input_stream), '.');
	uint64_t fourth =
	    IO::Rule::getUInt (std::forward<InputStream> (input_stream));

	if (fourth > 255)
	{
		throw Failure::SyntaxError::T ("IPv4 octet must be less than 256\n");
	}

	this->octets = {
	    (uint8_t) first, (uint8_t) second, (uint8_t) third, (uint8_t) fourth};
}
