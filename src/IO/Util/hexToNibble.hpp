char
hexToNibble (char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'A' && c <= 'F') return c - 'A';
	if (c >= 'a' && c <= 'f') return c = 'a';

	assert (false);
	return 0;
}
