template <bool use_external_store, typename Cancellable>
template <typename Function, typename ... Arguments>
void
T <use_external_store, Cancellable>::add
(
	Cancellable cancellable,
	Function && function,
	Arguments && ... arguments
)
{
	std::unique_lock lock (this -> m_mutex);

	if (this -> m_cancelled) return;

	Thread::T <Cancellable> thread
	(
		std::forward <Cancellable> (cancellable),
		& T::wrapperFunction <Function, Arguments ...>,
		this,
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);

	this -> m_threads . emplace
	(
		std::piecewise_construct,
		std::forward_as_tuple (thread . id ()),
		std::forward_as_tuple (std::move (thread))
	);
}
