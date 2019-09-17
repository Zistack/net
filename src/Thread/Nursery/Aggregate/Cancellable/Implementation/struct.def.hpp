template
<
	template <typename ...> typename ArgumentPackContainer,
	typename Cancellable,
	typename Function,
	typename ... Arguments
>
struct T <ArgumentPackContainer <Cancellable, Function, Arguments ...>>
{
	using Type = Cancellable;
};
