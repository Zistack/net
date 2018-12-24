std::string
T::hexadecitetToString (uint16_t hexadecitet)
{
	std::string hexadecitet_string;

	char h;
	bool leading = true;

	int i;
	for (i = 3; i >= 0; --i)
	{
		h = IO::Util::nibbleToHex<IO::Case::LOWER> (
		    (hexadecitet >> (i * 4)) & 0xF);
		if (h != '0' || !leading)
		{
			hexadecitet_string.push_back (h);
			leading = false;
		}
	}

	if (leading) hexadecitet_string.push_back ('0');

	return hexadecitet_string;
}
