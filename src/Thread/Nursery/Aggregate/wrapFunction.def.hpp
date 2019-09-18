template <bool use_external_store, typename ... Cancellables>
template
<
	template <typename ...> typename ArgumentPackContainer,
	typename Cancellable,
	typename Function,
	typename ... Arguments,
	std::size_t ... index
>
auto
T <use_external_store, Cancellables ...>::wrapFunction
(
	T <use_external_store, Cancellables ...> * aggregate,
	ArgumentPackContainer
	<
		Cancellable &,
		Function &&,
		Arguments && ...
	> && arguments,
	std::index_sequence <index ...>
)
{
	return std::forward_as_tuple
	(
		std::forward <Cancellable &> (std::get <0> (arguments)),
		& T::wrapperFunction <Function, Arguments ...>,
		aggregate,
		std::forward <Function> (std::get <1> (arguments)),
		std::forward <Arguments> (std::get <2 + index> (arguments)) ...
	);
}

template <bool use_external_store, typename ... Cancellables>
template
<
	template <typename ...> typename ArgumentPackContainer,
	typename Cancellable,
	typename Function,
	typename ... Arguments
>
auto
T <use_external_store, Cancellables ...>::wrapFunction
(
	T <use_external_store, Cancellables ...> * aggregate,
	ArgumentPackContainer
	<
		Cancellable &,
		Function &&,
		Arguments && ...
	> && arguments
)
{
	return wrapFunction
	(
		aggregate,
		std::forward <decltype (arguments)> (arguments),
		std::index_sequence_for <Arguments ...> {}
	);
}
