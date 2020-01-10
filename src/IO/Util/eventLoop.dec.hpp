template
<
	typename Watchable,
	typename ShutdownSignal,
	typename StreamEvent,
	typename WaitEvent = std::nullptr_t
>
void
eventLoop
(
	Failure::ExceptionStore::T & exception_store,
	Watchable && watchable,
	ShutdownSignal && shutdown_signal,
	StreamEvent && streamEvent,
	WaitEvent && waitEvent = nullptr
);
