void
T::setUnboundedIdentity ()
{
	this->stages.clear ();
	this->stages.emplace_back (new UnboundedIdentity::T ());
}
