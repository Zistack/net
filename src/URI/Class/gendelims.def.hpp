bool
gendelims (char c)
{
	return
		c == ':' ||
		c == '/' ||
		c == '?' ||
		c == '#' ||
		c == '[' ||
		c == ']' ||
		c == '@';
}
