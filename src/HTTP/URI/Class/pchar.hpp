bool
pchar (char c)
{
	return unreserved (c) ||
		c == ':' ||
		c == '@' ||
		c == '&' ||
		c == '=' ||
		c == '+' ||
		c == '$' ||
		c == ',';
}
