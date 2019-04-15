using T = TypeTraits::Filter::T
<
	HTTP::Entity::Readers::T,
	Failure::TypeTraits::IsCancellable::T,
	Failure::CancellableSlot::T
>;
