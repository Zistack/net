void
T::setUnboundedIdentity ()
{
	this->stages = std::list ({Stage::T (
	    std::unique_ptr<TransferEncoding::T> (new UnboundedIdentity::T ()))});
}
