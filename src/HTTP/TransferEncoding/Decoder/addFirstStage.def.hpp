void
T::addFirstStage
(
	const Header::TransferEncoding::Specification::T & specification
)
{
	if (specification . identifier == "chunked")
	{
		this -> stages . emplace_back (std::in_place_type <Chunked::Decode::T>);
	}
	else
	{
		this -> addStage (specification);
	}
}
