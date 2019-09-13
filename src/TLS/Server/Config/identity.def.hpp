const KeyPair::T &
T::identity () const
{
	return this -> value <Spec::IDENTITY> ();
}

KeyPair::T &
T::identity ()
{
	return this -> value <Spec::IDENTITY> ();
}
