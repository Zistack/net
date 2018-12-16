bool
rnchar (char c)
{
	return unreserved (c) || subdelims (c);
}
