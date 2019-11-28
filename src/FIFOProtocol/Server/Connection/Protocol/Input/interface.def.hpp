template <typename Interface, typename Request, typename Response>
const Interface &
T <Interface, Request, Response>::interface () const
{
	return static_cast <Interface &> (* this);
}

template <typename Interface, typename Request, typename Response>
Interface &
T <Interface, Request, Response>::interface ()
{
	return static_cast <Interface &> (* this);
}
