template <typename ... Cancellables>
template <typename Cancellable, typename Function, typename ... Arguments>
auto
T <Cancellables ...>::wrapFunction
(
	T <Cancellables ...> * aggregate,
	Cancellable && cancellable,
	Function && function,
	Arguments && ... arguments
)
{
	return std::forward_as_tuple
	(
		std::forward <Cancellable> (cancellable),
		& T::wrapperFunction,
		aggregate,
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);
}
