void
T::addLastStage
(
	const Header::TransferEncoding::Specification::T & specification,
	uint64_t chunk_size
)
{
	if (specification . identifier == "chunked")
	{
		this -> m_stages . emplace_back
		(
			std::in_place_type <Chunked::Encode::T>,
			chunk_size
		);
	}
	else
	{
		this -> addStage (specification);
	}
}
