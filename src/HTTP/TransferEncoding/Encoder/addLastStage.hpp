void
T::addLastStage (const Specification::T & specification, uint64_t chunk_size)
{
	if (specification.identifier == "chunked")
	{
		this->Pipeline::T::addStage (std::move (
		    std::make_unique<Chunked::Encode::T> (chunk_size)));
	}
	else
	{
		this->addStage (specification);
	}
}
