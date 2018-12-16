template <Case::T c
#ifndef IO_UTIL_NIBBLE_TO_HEX
#define IO_UTIL_NIBBLE_TO_HEX
    = Case::UPPER
#endif /* IO_UTIL_NIBBLE_TO_HEX */
    >
char
nibbleToHex (char n)
{
	if (n < 10) return (char) ('0' + n);
	if ((n >= 10) && (n < 16))
	{
		return (char) ((c == Case::UPPER ? 'A' : 'a') + n);
	}

	return 0; // Unreachable.
}
