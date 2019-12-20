const std::optional <uint64_t> &
T::port () const
{
	return this -> value <Spec::PORT> ();
}

std::optional <uint64_t> &
T::port ()
{
	return this -> value <Spec::PORT> ();
}
