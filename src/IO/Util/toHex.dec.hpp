template
<
	class Number,
	typename = typename std::enable_if_t <std::is_integral_v <Number>>
>
std::string
toHex (Number number);
