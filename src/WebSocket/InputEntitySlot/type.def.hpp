using T = TypeTraits::Filter::T
<
	TypeTraits::Map::T <HTTP::Entity::Writers::T, std::remove_reference_t>,
	Failure::IsCancellable::T,
	Failure::CancellableSlot::T
>;
