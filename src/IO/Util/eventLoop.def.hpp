// The template here assumes that you're gonna use lambdas for the callable
// arguments.
template
<
	typename Watchable,
	typename ShutdownSignal,
	typename StreamEvent,
	typename WaitEvent
>
void
eventLoop
(
	Failure::ExceptionStore::T & exception_store,
	Watchable && watchable,
	ShutdownSignal && shutdown_signal,
	StreamEvent && streamEvent,
	WaitEvent && waitEvent
)
{
	try
	{
		while (true)
		{
			try
			{
				if constexpr (IsBuffered::T <Watchable>::value)
				{
					if (watchable . isReady ()) break;
				}

				if constexpr
				(
					! std::is_same_v <WaitEvent, std::nullptr_t>
				)
				{
					waitEvent ();
				}

				IO::Util::wait
				(
					std::forward <Watchable> (watchable),
					std::forward <ShutdownSignal> (shutdown_signal)
				);

				if constexpr (IsSpurious::T <Watchable>::value)
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
				streamEvent ();
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
