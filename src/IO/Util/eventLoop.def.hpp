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
)
{
	try
	{
		while (true)
		{
			try
			{
				if constexpr (TypeTraits::IsBuffered::T <Watchable>::value)
				{
					if (watchable . isReady ()) break;
				}

				IO::Util::wait
				(
					std::forward <Watchable> (watchable),
					std::forward<ShutdownSignal> (shutdown_signal)
				);

				if constexpr (TypeTraits::IsSpurious::T <Watchable>::value)
				{
					if (watchable . spurious ()) continue;
				}
			}
			catch (Failure::CancelException::T)
			{
				break;
			}

			try
			{
				event (std::forward <Arguments> (arguments) ...);
			}
			catch (Failure::EndOfResource::T)
			{
				break;
			}
		}
	}
	catch (...)
	{
		exception_store . store (std::current_exception ());
	}
}
