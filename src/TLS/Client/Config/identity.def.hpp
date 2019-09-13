const std::optional <KeyPair::T> &
T::identity () const
{
	return this -> value <Spec::IDENTITY> ();
}

std::optional <KeyPair::T> &
T::identity ()
{
	return this -> value <Spec::IDENTITY> ();
}
