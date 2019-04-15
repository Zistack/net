template <typename Dispatcher>
template <typename InputStream>
void
T <Dispatcher>::waitForCloseFrame (InputStream && input_stream)
{
	ShutdownSignal::T wait_shutdown_signal;

	SuppressingScope::T wait_scope
	(
		wait_shutdown_signal,
		this -> exception_store
	);

	Thread::Timer::T
	(
		this -> close_timeout,
		& InputStream::cancel,
		& input_stream
	);

	IO::Util::eventLoop
	(
		this -> exception_store,
		std::forward <InputStream> (input_stream),
		wait_shutdown_signal,
		& T::waitEvent <InputStream>,
		this,
		std::forward <InputStream> (input_stream)
	);
}
