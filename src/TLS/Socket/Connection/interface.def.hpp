template <typename Interface, typename Specialization>
const Interface &
T <Interface, Specialization>::interface () const
{
	return static_cast <const Interface &> (* this);
}

template <typename Interface, typename Specialization>
Interface &
T <Interface, Specialization>::interface ()
{
	return static_cast <Interface &> (* this);
}
