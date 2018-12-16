void
T::setUnboundedIdentity ()
{
	this->stages = {std::unique_ptr<Stage::T> (new UnboundedIdentity::T ())};
}
