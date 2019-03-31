bool
twoByte (char c)
{
	unsigned char uc = (unsigned char) c;
	return (uc >= 0xC0) && (uc < 0xE0);
}

bool
twoByte (char32_t c)
{
	return (c >= 0x80) && (c < 0x800);
}
