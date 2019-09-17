template <bool use_external_store, typename ... Cancellables>
template <typename Function, typename ... Arguments>
void
T <use_external_store, Cancellables ...>::wrapperFunction
(
	T <use_external_store, Cancellables ...> * aggregate,
	Function && function,
	Arguments && ... arguments
)
{
	bool first_fail = aggregate -> m_exception_store . tryStore
	(
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);

	if (first_fail) aggregate -> cancel ();
}
