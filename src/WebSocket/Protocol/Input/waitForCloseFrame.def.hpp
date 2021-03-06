template <typename Interface>
template <typename InputStream>
void
T <Interface>::waitForCloseFrame (InputStream && input_stream)
{
	ShutdownSignal::T wait_shutdown_signal;

	SuppressingScope::T wait_scope
	(
		wait_shutdown_signal,
		this -> m_exception_store
	);

	Thread::Timer::T
	(
		this -> m_close_timeout,
		[&] () { input_stream . cancel (); }
	);

	IO::Util::eventLoop
	(
		this -> m_exception_store,
		std::forward <InputStream> (input_stream),
		wait_shutdown_signal,
		[&] ()
		{
			this -> waitEvent (std::forward <InputStream> (input_stream));
		}
	);
}
