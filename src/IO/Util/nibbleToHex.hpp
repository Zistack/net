template <Case::T c
#ifndef IO_Util_nibbleToHex_hpp
#define IO_Util_nibbleToHex_hpp
    = Case::UPPER
#endif /* IO_Util_nibbleToHex_hpp */
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
