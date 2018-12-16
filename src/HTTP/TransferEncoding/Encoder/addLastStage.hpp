void
T::addLastStage (const Specification::T & specification)
{
	if (specification.identifier == "chunked")
	{
		// Right now, we're hardcoding the chunk size.  Later, we want to pull
		// this from a configuration somewhere server-side.
		this->Pipeline::T::addStage (
		    std::move (std::make_unique<Chunked::Encode::T> (4096)));
	}
	else
	{
		this->addStage (specification);
	}
}
