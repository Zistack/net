template
<
	typename InputStream,
	template <typename ...> typename CancellablePackContainer,
	typename ... Cancellables
>
struct T <InputStream, CancellablePackContainer <Cancellables ...>>
{
	using Type = Failure::CancellableSlot::T
	<
		std::remove_reference_t <InputStream>,
		Cancellables ...
	>;
};
