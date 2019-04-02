bool
qchar (char c)
{
	return pchar (c) || c == '/' || c == '?';
}
