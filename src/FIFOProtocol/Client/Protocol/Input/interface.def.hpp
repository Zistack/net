template <typename Interface, typename Response>
const Interface &
T <Interface, Response>::interface () const
{
	return static_cast <Interface &> (* this);
}

template <typename Interface, typename Response>
Interface &
T <Interface, Response>::interface ()
{
	return static_cast <Interface &> (* this);
}
