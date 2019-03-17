template <typename Request, typename Response, typename Interface>
Response
T<Request, Response, Interface>::makeRequest (const Request & request)
{
	Thread::Delay::T<Response> response_delay;

	{
		std::unique_lock<decltype (this->queue_mutex)> queue_lock (
		    this->queue_mutex);

		this->input.push (response_delay);

		this->output.push (request);
	}

	try
	{
		Thread::Timer::T (this->round_trip_timeout,
		    Thread::Delay::T<Response>::cancel,
		    &response_delay);
		return this->response_delay.get ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Request timed out\n");
	}
}
