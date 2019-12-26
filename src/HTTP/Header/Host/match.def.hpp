bool
T::match (const URI::T & uri)
{
	if (! uri . authority) return true;

	if (uri . authority -> host != this -> host) return false;

	if (uri . authority -> port != this -> port) return false;

	return true;
}
