template <class RequestType, class ResponseType>
ResponseType
T<RequestType, ResponseType>::makeRequest (RequestType request)
{
	const std::string message_prefix =
	    "IO::FIFOProtocol::Client::T::makeRequest\n";

	std::unique_lock<decltype (this->status_bit)> lock (this->status_bit);

	if (!this->status_bit)
	{
		throw Failure::Error::T (message_prefix + "Protocol is not running\n");
	}

	Protocol::Delay::T<ResponseType> response;

	try
	{
		response = this->response_queue.push ();
	}
	catch (Failure::CancelException::T & e)
	{
		// This should never actually occur, though the code is harmless in any
		// case.
		throw Failure::Error::T (
		    message_prefix + "Response queue is inactive\n");
	}

	Thread::Timer::T round_trip_timer (
	    this->round_trip_timeout, [&response]() { response.cancel (); });

	try
	{
		try
		{
			{
				Thread::Timer::T output_timer (this->output_timeout,
				    [this]() { this->output_timeout_signal.send (); });
				this->writeRequest (request, this->output_stream);
			}
			this->output_timeout_signal.recieve ();
		}
		catch (Failure::CancelException::T)
		{
			throw Failure::Error::T (
			    message_prefix + "Writing request timed out\n");
		}

		lock.unlock ();

		try
		{
			return response.get ();
		}
		catch (Failure::CancelException::T)
		{
			throw Failure::Error::T (message_prefix + "Operation timed out\n");
		}
		catch (Failure::Error::T & e)
		{
			throw e.set (message_prefix + e.what ());
		}
	}
	catch (...)
	{
		this->stop ();
		throw;
	}
}
