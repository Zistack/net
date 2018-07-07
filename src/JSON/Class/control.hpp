bool
control (char c)
{
	unsigned char uc = (unsigned char) c;
	return (uc < 32) || (uc >= 127);
}
