template <typename Interface>
template <typename ProxyInterface, typename>
const ProxyInterface &
T <Interface>::interface () const
{
	return static_cast <const Interface &> (* this);
}

template <typename Interface>
template <typename ProxyInterface, typename>
ProxyInterface &
T <Interface>::interface ()
{
	return static_cast <Interface &> (* this);
}
