bool
fourByte (char c)
{
	unsigned char uc = (unsigned char) c;
	return (uc >= 0xF0) && (uc < 0xF1);
}

bool
fourByte (char32_t c)
{
	return (c >= 0x10000) && (c < 0x110000);
}
