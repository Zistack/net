bool
reserved (char c)
{
	return gendelims (c) || subdelims (c);
}
