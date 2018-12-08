void
T::setBoundedIdentity (size_t size)
{
	this->stages = std::list ({Stage::T (
	    std::unique_ptr<TransferEncoding::T> (new BoundedIdentity::T (size)))});
}
