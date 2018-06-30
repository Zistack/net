bool
hex (char c)
{
	return (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') || digit (c);
}
