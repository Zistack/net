bool
pchar (char c)
{
	return unreserved (c) || subdelims (c) || c == ':' || c == '@';
}
