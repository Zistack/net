bool
oneByte (char c)
{
	unsigned char uc = (unsigned char) c;
	return uc < 0x80;
}

bool
oneByte (char32_t c)
{
	return c < 0x80;
}
