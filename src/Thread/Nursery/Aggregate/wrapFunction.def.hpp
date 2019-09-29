template <bool use_external_store, typename ... Cancellables>
template
<
	template <typename ...> typename ArgumentPackContainer,
	typename Cancellable,
	typename Function,
	typename ... Arguments
>
void
T <use_external_store, Cancellables ...>::wrapFunction
(
	Thread::T <Filter::T <Cancellable>> & thread,
	ArgumentPackContainer
	<
		Cancellable,
		Function,
		Arguments ...
	> & arguments
)
{
	this -> wrapFunctionImplementation
	(
		thread,
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
void
T <use_external_store, Cancellables ...>::wrapFunction
(
	Thread::T <Filter::T <Cancellable>> & thread,
	ArgumentPackContainer
	<
		Cancellable,
		Function,
		Arguments ...
	> && arguments
)
{
	this -> wrapFunctionImplementation
	(
		thread,
		arguments,
		std::index_sequence_for <Arguments ...> {}
	);
}
