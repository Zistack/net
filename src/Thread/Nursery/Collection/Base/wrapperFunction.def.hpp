template <typename Cancellable>
template <typename Function, typename ... Arguments>
void
T <Cancellable>::wrapperFunction
(
	T * collection,
	Function && function,
	Arguments && ... arguments
)
{
	bool first_fail = collection -> m_exception_store . tryStore
	(
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);

	if (first_fail) collection -> cancel ();

	std::unique_lock lock (collection -> m_mutex);

	auto thread = collection -> m_threads . find (std::this_thread::get_id ());

	thread -> detach ();
	collection -> m_threads . erase (thread);

	collection -> m_condition_variable . notify_all ();
}
