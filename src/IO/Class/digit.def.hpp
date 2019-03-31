bool
digit (char c)
{
	unsigned char uc = (unsigned char) c;
	return (uc >= '0') && (uc <= '9');
}
