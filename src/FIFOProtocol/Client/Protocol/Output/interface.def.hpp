template <typename Interface, typename Request>
const Interface &
T <Interface, Request>::interface () const
{
	return static_cast <Interface &> (* this);
}

template <typename Interface, typename Request>
Interface &
T <Interface, Request>::interface ()
{
	return static_cast <Interface &> (* this);
}
