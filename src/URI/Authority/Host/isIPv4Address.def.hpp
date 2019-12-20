bool
isIPv4Address (const T & host)
{
	return std::holds_alternative <IPv4Address::T> (host);
}
