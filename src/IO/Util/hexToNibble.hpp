char
hexToNibble (char c)
{
	if (c >= '0' && c <= '9') return (char) (c - '0');
	if (c >= 'A' && c <= 'F') return (char) (c - 'A');
	if (c >= 'a' && c <= 'f') return (char) (c - 'a');

	return 0; // Unreachable.
}
