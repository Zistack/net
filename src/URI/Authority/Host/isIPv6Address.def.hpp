bool
isIPv6Address (const T & host)
{
	return std::holds_alternative <IPv6Address::T> (host);
}
