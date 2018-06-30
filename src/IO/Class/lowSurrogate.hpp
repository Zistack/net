bool
lowSurrogate (char16_t c)
{
	return (c >= 0xDC00) && (c < 0xE000);
}
