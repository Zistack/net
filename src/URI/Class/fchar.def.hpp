bool
fchar (char c)
{
	return pchar (c) || c == '/' || c == '?';
}
