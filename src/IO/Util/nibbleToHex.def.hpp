template <Case::T c>
char
nibbleToHex (char n)
{
	if (n < 10) return (char) ('0' + n);
	if ((n >= 10) && (n < 16))
	{
		return (char) ((c == Case::UPPER ? 'A' : 'a') + (n - 10));
	}

	return 0; // Unreachable.
}
