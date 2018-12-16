void
T::addFirstStage (const Specification::T & specification)
{
	if (specification.identifier == "chunked")
	{
		this->Pipeline::T::addStage (
		    std::move (std::make_unique<Chunked::Decode::T> ()));
	}
	else
	{
		this->addStage (specification);
	}
}
