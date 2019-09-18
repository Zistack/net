template <bool use_external_store, typename ... Cancellables>
template <typename Cancellable, typename Function, typename ... Arguments>
auto
T <use_external_store, Cancellables ...>::wrapFunction
(
	T <use_external_store, Cancellables ...> * aggregate,
	Cancellable & cancellable,
	Function && function,
	Arguments && ... arguments
)
{
	return std::forward_as_tuple
	(
		cancellable,
		& T::wrapperFunction,
		aggregate,
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);
}
