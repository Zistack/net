bool
twoByte (char c)
{
	return (c >= 0xC0) && (c < 0xE0);
}

bool
twoByte (char32_t c)
{
	return (c >= 0x80) && (c < 0x800);
}
