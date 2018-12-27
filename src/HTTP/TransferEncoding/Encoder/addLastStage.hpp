void
T::addLastStage (const Specification::T & specification)
{
	if (specification.identifier == "chunked")
	{
		this->Pipeline::T::addStage (std::move (
		    std::make_unique<Chunked::Encode::T> (this->config.chunk_size)));
	}
	else
	{
		this->addStage (specification);
	}
}
