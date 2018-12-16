template <Case::T c
#ifndef IO_RULE_PUT_HEX
#define IO_RULE_PUT_HEX
    = Case::UPPER
#endif /* IO_RULE_PUT_HEX */
    >
void
putUpperHex (uint64_t num, Interface::OutputStream::T & output_stream)
{
	std::string hex_string;

	int i;
	for (i = sizeof (num) * 2 - 1; i >= 0; --i)
	{
		hex_string.push_back (Util::nibbleToHex<c> ((num >> (i * 4)) & 0xF));
	}

	output_stream.print (hex_string);
}
