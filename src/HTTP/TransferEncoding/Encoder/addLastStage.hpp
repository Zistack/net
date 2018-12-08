void
T::addLastStage (const Specification::T & specification)
{
	if (specification.identifier == "chunked")
	{
		// Right now, we're hardcoding the chunk size.  Later, we want to pull
		// this from a configuration somewhere server-side.
		this->addStage (std::unique_ptr<TransferEncoding::T> (
		    new Chunked::Encode::T (4096)));
	}
	else
	{
		this->addStage (specification);
	}
}
