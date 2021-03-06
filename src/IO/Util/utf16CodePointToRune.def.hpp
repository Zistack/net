char32_t
utf16CodePointToRune (std::u16string code_point)
{
	char32_t rune = 0;

	switch (code_point . size ())
	{
	case 1:
		rune |= (char32_t) (code_point [0] & 0xFFFF);
		return rune;
	case 2:
		rune |= (char32_t) (code_point [0] & 0x03FF) << 10;
		rune |= (char32_t) (code_point [1] & 0x03FF);
		return rune;
	}

	return rune; // Unreachable.
}
