std::string
charToHex (char c)
{
	return {nibbleToHex ((char) (c >> 4 & 0xF)),
	    nibbleToHex ((char) (c >> 0 & 0xF))};
}

std::string
charToHex (char16_t c)
{
	return {nibbleToHex ((char) (c >> 12 & 0xF)),
	    nibbleToHex ((char) (c >> 8 & 0xF)),
	    nibbleToHex ((char) (c >> 4 & 0xF)),
	    nibbleToHex ((char) (c >> 0 & 0xF))};
}

std::string
charToHex (char32_t c)
{
	return {nibbleToHex ((char) (c >> 28 & 0xF)),
	    nibbleToHex ((char) (c >> 24 & 0xF)),
	    nibbleToHex ((char) (c >> 20 & 0xF)),
	    nibbleToHex ((char) (c >> 16 & 0xF)),
	    nibbleToHex ((char) (c >> 12 & 0xF)),
	    nibbleToHex ((char) (c >> 8 & 0xF)),
	    nibbleToHex ((char) (c >> 4 & 0xF)),
	    nibbleToHex ((char) (c >> 0 & 0xF))};
}
