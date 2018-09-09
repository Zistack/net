template <class RequestType, class ResponseType>
ResponseType
T<RequestType, ResponseType>::makeRequest (RequestType request)
{
	const std::string message_prefix =
	    "IO::FIFOProtocol::Client::T::makeRequest\n";

	std::unique_lock<T<RequestType, ResponseType>> lock (*this);

	if (!active)
		throw Failure::Error::T (message_prefix + "Protocol not active\n");

	std::promise<ResponseType> promise;

	Thread::Timer::T round_trip_timer (this->round_trip_timeout, [&promise]() {
		try
		{
			promise.set_exception (
			    std::make_exception_ptr (Failure::CancelException::T ()));
		}
		catch (std::future_error)
		{
		}
	});

	try
	{
		try
		{
			{
				Thread::Timer::T output_timer (this->output_timeout,
				    [this]() { this->output_timeout_signal->send (); });
				this->writeRequest (request, this->output_stream);
			}
			this->output_timeout_signal->recieve ();
		}
		catch (Failure::CancelException::T)
		{
			throw Failure::Error::T (
			    message_prefix + "Writing request timed out\n");
		}

		this->response_queue.push (&promise);

		lock.unlock ();

		try
		{
			return promise.get_future ().get ();
		}
		catch (Failure::CancelException::T)
		{
			throw Failure::Error::T (
			    message_prefix + "Transaction timed out\n");
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
