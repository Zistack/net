bool
secondDelimiter (char c)
{
	return c == '/' || c == '?' || c == '#' || ! urichar (c);
}
