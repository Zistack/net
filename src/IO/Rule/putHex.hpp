template <typename Number,
    typename OutputStream,
    typename
#ifndef IO_Rule_putHex_hpp
#define IO_Rule_putHex_hpp
    = typename std::enable_if<std::is_integral<Number>::value>::type
#endif /* IO_Util_toHex_hpp */
    >
void
putHex (Number num, OutputStream && output_stream)
{
	output_stream.print (Util::toHex (std::forward<Number> (num)));
}
