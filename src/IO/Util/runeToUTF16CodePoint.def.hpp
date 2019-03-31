std::u16string
runeToUTF16CodePoint (char32_t c)
{
	std::u16string code_point;

	if (Class::basicMultilingualPlane (c))
	{
		code_point . push_back ((char16_t) (c & 0xFFFF));
		return code_point;
	}
	if (Class::supplementaryPlane (c))
	{
		code_point . push_back ((char16_t) (((c >> 10) & 0x03FF) | 0xD800));
		code_point . push_back ((char16_t) (((c >> 0) & 0x03FF) | 0xDC00));
		return code_point;
	}

	return code_point;
}
