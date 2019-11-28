template <typename Interface, typename Protocol, typename Response>
const Interface &
T <Interface, Protocol, Response>::interface () const
{
	return static_cast <Interface &> (* this);
}

template <typename Interface, typename Protocol, typename Response>
Interface &
T <Interface, Protocol, Response>::interface ()
{
	return static_cast <Interface &> (* this);
}
