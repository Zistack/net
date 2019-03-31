template
<
	typename Watchable,
	typename ShutdownSignal,
	typename Function,
	typename ... Arguments
>
void
eventLoop
(
	Failure::ExceptionStore::T & exception_store,
	Watchable && watchable,
	ShutdownSignal && shutdown_signal,
	Function && event,
	Arguments && ... arguments
);
