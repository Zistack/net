using T = TypeTraits::Filter::T
<
	HTTP::Entity::Writers::T,
	Failure::TypeTraits::IsCancellable::T,
	Failure::CancellableSlot::T
>;
