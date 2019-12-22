bool
thirdDelimiter (char c)
{
	return c == '?' || c == '#' || ! urichar (c);
}
