template
<
	template <typename ...> typename ArgumentPackContainer,
	typename Cancellable,
	typename Function,
	typename ... Arguments
>
struct T <ArgumentPackContainer <Cancellable, Function, Arguments ...>>
{
	using Type = std::conditional_t
	<
		std::is_same_v <std::remove_reference_t <Cancellable>, std::nullptr_t>,
		std::nullptr_t,
		Cancellable
	>;
};


