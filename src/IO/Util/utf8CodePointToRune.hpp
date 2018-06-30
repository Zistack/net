char32_t
utf8CodePointToRune (std::string code_point)
{
	char32_t rune = 0;

	switch (code_point.size ())
	{
	case 1:
		rune |= (code_point [0] & 0x7F);
		return rune;
	case 2:
		rune |= (code_point [0] & 0x1F) << 6;
		rune |= (code_point [1] & 0x3F);
		return rune;
	case 3:
		rune |= (code_point [0] & 0x0F) << 12;
		rune |= (code_point [1] & 0x3F) << 6;
		rune |= (code_point [2] & 0x3F);
		return rune;
	case 4:
		rune |= (code_point [0] & 0x07) << 18;
		rune |= (code_point [1] & 0x3F) << 12;
		rune |= (code_point [2] & 0x3F) << 6;
		rune |= (code_point [3] & 0x3F);
		return rune;
	}
}
