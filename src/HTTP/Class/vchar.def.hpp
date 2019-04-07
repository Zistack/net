bool
vchar (char c)
{
	unsigned char uc = (unsigned char) c;
	return (uc >= 0x21) && (uc <= 0x7E);
}
