template <typename Cancellable, typename Function, typename ... Arguments>
bool
T::start
(
	Cancellable * cancellable,
	Function && function,
	Arguments && ... arguments
) noexcept
{
	std::unique_lock lock (this -> m_mutex);

	if (this -> m_cancelled) return false;

	if (this -> m_exception_store) return false;

	Thread::T thread
	(
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...,
		cancellable
	);

	this -> m_threads . insert ({thread . id (), std::move (thread)});

	return true;
}
