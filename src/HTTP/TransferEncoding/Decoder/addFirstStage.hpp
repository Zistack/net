void
T::addFirstStage (const Specification::T & specification)
{
	if (specification.identifier == "chunked")
	{
		this->addStage (
		    std::unique_ptr<TransferEncoding::T> (new Chunked::Decode::T ()));
	}
	else
	{
		this->addStage (specification);
	}
}
