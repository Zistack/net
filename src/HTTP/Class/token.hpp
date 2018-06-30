bool
token (char c)
{
	return character (c) && ! separator (c);
}
