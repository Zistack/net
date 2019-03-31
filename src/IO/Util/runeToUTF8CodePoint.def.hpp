std::string
runeToUTF8CodePoint (char32_t rune)
{
	std::string utf8;

	if (Class::oneByte (rune))
	{
		utf8 . push_back ((char) (((rune >> 0) & 0x7F) | 0x00));
	}
	if (Class::twoByte (rune))
	{
		utf8 . push_back ((char) (((rune >> 6) & 0x1F) | 0xC0));
		utf8 . push_back ((char) (((rune >> 0) & 0x3F) | 0x80));
	}
	if (Class::threeByte (rune))
	{
		utf8 . push_back ((char) (((rune >> 12) & 0x0F) | 0xE0));
		utf8 . push_back ((char) (((rune >> 6) & 0x3F) | 0x80));
		utf8 . push_back ((char) (((rune >> 0) & 0x3F) | 0x80));
	}
	if (Class::fourByte (rune))
	{
		utf8 . push_back ((char) (((rune >> 18) & 0x07) | 0xF0));
		utf8 . push_back ((char) (((rune >> 12) & 0x3F) | 0x80));
		utf8 . push_back ((char) (((rune >> 6) & 0x3F) | 0x80));
		utf8 . push_back ((char) (((rune >> 0) & 0x3F) | 0x80));
	}

	return utf8;
}
