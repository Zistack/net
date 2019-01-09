template <class Function, class... Arguments>
void
eventLoop (Failure::ExceptionStore::T & exception_store,
    IO::Interface::Watchable::T & watchable,
    IO::Interface::Watchable::T & shutdown_signal,
    Function && event,
    Arguments &&... arguments)
{
	exception_store.tryStore ([&]() {
		while (true)
		{
			try
			{
				IO::Util::wait (watchable, shutdown_signal);
			}
			catch (Failure::CancelException::T)
			{
				break;
			}

			try
			{
				event (std::forward<Arguments> (arguments)...);
			}
			catch (IO::EOF::T)
			{
				break;
			}
		}
	});
}
