void
T::addUnboundedIdentity ()
{
	this -> m_stages . emplace_back (std::in_place_type <UnboundedIdentity::T>);
}
