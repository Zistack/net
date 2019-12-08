template
<
	typename OutputStream,
	template <typename ...> typename CancellablePackContainer,
	typename ... Cancellables
>
struct T <OutputStream, CancellablePackContainer <Cancellables ...>>
{
	using Type = Failure::CancellableSlot::T
	<
		std::remove_reference_t <OutputStream>,
		Cancellables ...
	>;
};
