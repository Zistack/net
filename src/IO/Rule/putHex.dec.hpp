template
<
	typename Number,
	typename OutputStream,
	typename = std::enable_if_t <std::is_integral_v <Number>>
>
void
putHex (Number num, OutputStream && output_stream);
