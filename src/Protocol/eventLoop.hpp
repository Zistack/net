void
eventLoop (Failure::ExceptionStore::T & exception_store,
    IO::Interface::Watchable::T * watchable,
    Shutdown::Signal::T & shutdown_signal,
    std::function<void(void)> event)
{
	Shutdown::Scope::T shutdown_scope (shutdown_signal, &exception_store);

	exception_store.tryStore ([&]() {
		while (true)
		{
			try
			{
				IO::Util::wait (watchable, &shutdown_signal);
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
