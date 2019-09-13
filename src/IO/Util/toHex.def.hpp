template <typename Number, typename>
std::string
toHex (Number number)
{
	std::string hex_string;

	int i;
	for (i = (sizeof (number) * 2) - 1; i >= 0; --i)
	{
		hex_string . push_back (nibbleToHex ((number >> (i * 4)) & 0xF));
	}

	return hex_string;
}
