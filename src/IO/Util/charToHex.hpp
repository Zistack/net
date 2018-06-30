std::string
charToHex (char c)
{
	return {
		nibbleToHex (c >> 4 & 0xF),
		nibbleToHex (c >> 0 & 0xF)
	};
}

std::string
charToHex (char16_t c)
{
	return {
		nibbleToHex (c >> 12 & 0xF),
		nibbleToHex (c >> 8 & 0xF),
		nibbleToHex (c >> 4 & 0xF),
		nibbleToHex (c >> 0 & 0xF)
	};
}

std::string
charToHex (char32_t c)
{
	return {
		nibbleToHex (c >> 28 & 0xF),
		nibbleToHex (c >> 24 & 0xF),
		nibbleToHex (c >> 20 & 0xF),
		nibbleToHex (c >> 16 & 0xF)
		nibbleToHex (c >> 12 & 0xF),
		nibbleToHex (c >> 8 & 0xF),
		nibbleToHex (c >> 4 & 0xF),
		nibbleToHex (c >> 0 & 0xF)
	}
}
