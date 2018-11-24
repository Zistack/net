bool
vchar (char c)
{
	unsigned char u = c;
	return (u >= 0x21) && (u <= 0x7E);
}
