bool
hex (char c)
{
	unsigned char uc = (unsigned char) c;
	return digit (c) || ((uc >= 'A') && (uc <= 'F')) ||
	    ((uc >= 'a') && (uc <= 'f'));
}
