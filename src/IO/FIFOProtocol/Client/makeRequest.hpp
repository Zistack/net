template <class RequestType, class ResponseType>
ResponseType
T<RequestType, ResponseType>::makeRequest (RequestType request)
{
	const std::string message_prefix =
	    "IO::FIFOProtocol::Client::T::makeRequest\n";

	try
	{
		std::unique_lock<T<RequestType, ResponseType>> lock (*this);

		if (!active) throw Failure::ResourceError::T ("Protocol not active");

		std::promise<ResponseType> promise;

		Thread::Timeout::T (this->round_trip_timeout, [&]() {
			try
			{
				promise.set_exception (std::make_exception_ptr (
				    Failure::CancelError::T ("Operation timed out")));
			}
			catch (std::future_error)
			{
			}
		});

		{
			Thread::Timeout::T (this->output_timeout,
			    [&]() { this->output_timeout_signal->send (); });
			this->writeRequest (request, this->output_stream);
		}
		this->output_timeout_signal->recieve ();

		this->response_queue.push (&promise);

		lock.unlock ();

		return promise.get_future ().get ();
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
