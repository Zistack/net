template <typename InputStream>
Authority::IPv6Address::T
T::getIPLiteral (InputStream && input_stream)
{
	IO::Util::expect (std::forward<InputStream> (input_stream), '[');

	Authority::IPv6Address::T ipv6address (
	    std::forward<InputStream> (input_stream));

	IO::Util::expect (std::forward<InputStream> (input_stream), ']');

	return ipv6address;
}
