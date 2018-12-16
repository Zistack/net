std::unique_ptr<Authority::IPv6Address::T>
getIPLiteral (IO::Interface::PeekableInputStream::T & input_stream)
{
	IO::Util::expect (input_stream, '[');

	std::unique_ptr<Authority::IPv6Address::T> ipv6address (
	    new Authority ::IPv6Address::T (input_stream));

	IO::Util::expect (input_stream, ']');

	return ipv6address;
}
