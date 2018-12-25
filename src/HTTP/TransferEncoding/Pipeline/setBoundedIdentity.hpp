void
T::setBoundedIdentity (size_t size)
{
	this->stages.clear ();
	this->stages.emplace_back (new BoundedIdentity::T (size));
}
