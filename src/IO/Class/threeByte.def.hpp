bool
threeByte (char c)
{
	unsigned char uc = (unsigned char) c;
	return (uc >= 0xE0) && (uc < 0xF0);
}

bool
threeByte (char32_t c)
{
	return (c >= 0x800) && (c < 0x10000);
}
