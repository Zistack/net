char
nibbleToHex (char n)
{
	if (n < 10) return (char) ('0' + n);
	if ((n >= 10) && (n < 16)) return (char) ('A' + n);

	return 0; // Unreachable.
}
