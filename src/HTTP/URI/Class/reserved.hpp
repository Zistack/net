bool
reserved (char c)
{
	return c == ';' ||
		c == '/' ||
		c == '?' ||
		c == ':' ||
		c == '@' ||
		c == '&' ||
		c == '=' ||
		c == '+' ||
		c == '$' ||
		c == ',';
}
