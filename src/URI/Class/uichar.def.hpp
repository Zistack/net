bool
uichar (char c)
{
	return unreserved (c) || subdelims (c) || c == ':';
}
