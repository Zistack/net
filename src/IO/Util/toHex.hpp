template <class Number,
    typename
#ifndef IO_Util_toHex_hpp
#define IO_Util_toHex_hpp
    = typename std::enable_if<std::is_integral<Number>::value>::type
#endif /* IO_Util_toHex_hpp */
    >
std::string
toHex (Number number)
{
	std::string hex_string;

	int i;
	for (i = (sizeof (number) * 2) - 1; i >= 0; --i)
	{
		hex_string.push_back (nibbleToHex ((number >> (i * 4)) & 0xF));
	}

	return hex_string;
}
