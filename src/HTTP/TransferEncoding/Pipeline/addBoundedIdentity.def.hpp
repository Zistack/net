template <typename Stage>
void
T <Stage>::addBoundedIdentity (size_t size)
{
	this -> stages . emplace_back
	(
		std::in_place_type <BoundedIdentity::T>,
		size
	);
}
