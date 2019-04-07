void
T::addUnboundedIdentity ()
{
	this -> stages . emplace_back (std::in_place_type <UnboundedIdentity::T>);
}
