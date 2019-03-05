template <typename Watchable,
    typename ShutdownSignal,
    typename Function,
    typename... Arguments>
void
eventLoop (Failure::ExceptionStore::T & exception_store,
    Watchable && watchable,
    ShutdownSignal && shutdown_signal,
    Function && event,
    Arguments &&... arguments)
{
	exception_store.tryStore ([&]() {
		while (true)
		{
			try
			{
				IO::Util::wait (std::forward<Watchable> (watchable),
				    std::forward<ShutdownSignal> (shutdown_signal));
			}
			catch (Failure::CancelException::T)
			{
				break;
			}

			try
			{
				event (std::forward<Arguments> (arguments)...);
			}
			catch (Failure::EndOfResource::T)
			{
				break;
			}
		}
	});
}
