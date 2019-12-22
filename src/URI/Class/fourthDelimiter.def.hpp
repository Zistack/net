bool
fourthDelimiter (char c)
{
	return c == '#' || ! urichar (c);
}
