template <typename Stage>
void
T <Stage>::addBoundedIdentity (size_t size)
{
	this -> m_stages . emplace_back
	(
		std::in_place_type <BoundedIdentity::T>,
		size
	);
}
