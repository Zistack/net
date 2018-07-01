bool
continuation (char c)
{
	unsigned char uc = (unsigned char) c;
	return (uc >= 0x80) && (uc < 0xC0);
}
