void
T::setBoundedIdentity (size_t size)
{
	this->stages = {std::unique_ptr<Stage::T> (new BoundedIdentity::T (size))};
}
