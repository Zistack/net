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
		Cancellable,
		Function,
		Arguments ...
	> & arguments
)
{
	return wrapFunctionImplementation
	(
		aggregate,
		arguments,
		std::index_sequence_for <Arguments ...> {}
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
		Cancellable,
		Function,
		Arguments ...
	> && arguments
)
{
	return wrapFunctionImplementation
	(
		aggregate,
		arguments,
		std::index_sequence_for <Arguments ...> {}
	);
}
