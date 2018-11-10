void
eventLoop (Failure::ExceptionStore::T & exception_store,
    IO::Interface::Watchable::T & watchable,
    IO::Interface::Watchable::T & shutdown_signal,
    std::function<void(void)> event)
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
				event ();
			}
			catch (IO::EOF::T)
			{
				break;
			}
		}
	});
}
