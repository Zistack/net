bool
highSurrogate (char16_t c)
{
	return (c >= 0xD800) && (c < 0xDC00);
}
