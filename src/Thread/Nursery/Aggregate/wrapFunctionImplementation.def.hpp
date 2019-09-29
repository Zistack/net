template <bool use_external_store, typename ... Cancellables>
template
<
	template <typename ...> typename ArgumentPackContainer,
	typename Cancellable,
	typename Function,
	typename ... Arguments,
	std::size_t ... index
>
void
T <use_external_store, Cancellables ...>::wrapFunctionImplementation
(
	Thread::T <Filter::T <Cancellable>> & thread,
	ArgumentPackContainer
	<
		Cancellable,
		Function,
		Arguments ...
	> & arguments,
	std::index_sequence <index ...>
)
{
	thread . run
	(
		T::wrapperFunction <Function, Arguments ...>,
		std::move (this),
		std::forward <Function> (std::get <1> (arguments)),
		std::forward <Arguments> (std::get <2 + index> (arguments)) ...
	);
}
