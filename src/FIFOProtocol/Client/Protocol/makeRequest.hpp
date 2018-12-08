template <class RequestType, class ResponseType>
ResponseType
T<RequestType, ResponseType>::makeRequest (const RequestType & request)
{
	const std::string message_prefix =
	    "IO::FIFOProtocol::Client::T::makeRequest\n";

	std::unique_lock<decltype (this->sleep_lock)> lock (this->sleep_lock);

	if (!this->status_bit)
	{
		throw Failure::Error::T (message_prefix + "Protocol is not running\n");
	}

	// This check is more of an optimization.  Nothing would break (more) if it
	// weren't here.
	if (!this->shutdown_signal.running ())
	{
		throw Failure::Error::T (
		    message_prefix + "Protocol is shutting down\n");
	}

	::Protocol::Delay::T<ResponseType> response_delay;
	ResponseType response;

	try
	{
		this->nursery->call (
		    [this, &request, &lock, &response_delay, &response]() {
			    try
			    {
				    this->response_queue.push (response_delay);
			    }
			    catch (Failure::CancelException::T & e)
			    {
				    // This should never actually occur, though the code is
				    // harmless in any case.
				    throw Failure::Error::T ("Response queue is inactive\n");
			    }

			    Thread::Timer::T round_trip_timer (this->round_trip_timeout,
			        [&response_delay]() { response_delay.cancel (); });

			    try
			    {
				    {
					    Failure::CancelScope::T output_cancel_scope;
					    Thread::Timer::T output_timer (
					        this->output_timeout, [&output_cancel_scope]() {
						        output_cancel_scope.cancel ();
					        });
					    this->writeRequest (request,
					        *this->output_stream,
					        this->output_cancel_signal,
					        output_cancel_scope);
				    }
				    this->output_cancel_signal.clear ();
			    }
			    catch (Failure::CancelException::T)
			    {
				    throw Failure::Error::T ("Writing request timed out\n");
			    }

			    lock.unlock ();

			    try
			    {
				    response = response_delay.get ();
			    }
			    catch (Failure::CancelException::T)
			    {
				    throw Failure::Error::T ("Operation cancelled\n");
			    }
		    },
		    [&response_delay]() { response_delay.cancel (); });
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}

	return response;
}
