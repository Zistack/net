template <typename Interface>
const Interface &
T <Interface>::interface () const
{
	return static_cast <Interface &> (* this);
}

template <typename Interface>
Interface &
T <Interface>::interface ()
{
	return static_cast <Interface &> (* this);
}
