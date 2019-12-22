bool
urichar (char c)
{
	return reserved (c) || unreserved (c) || c == '%';
}
