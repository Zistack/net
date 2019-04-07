template
<
	typename InputStream,
	template <typename ...> typename CancellablePackContainer,
	typename ... Cancellables
>
struct T <InputStream, CancellablePackContainer <Cancellables ...>>
{
	using Type = Failure::CancellableSlot::T <InputStream, Cancellables ...>;
};
