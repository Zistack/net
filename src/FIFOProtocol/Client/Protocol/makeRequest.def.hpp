template <typename Request, typename Response, typename Interface>
Response
T <Request, Response, Interface>::makeRequest (const Request & request)
{
	Thread::Delay::T <Response> response_delay;

	{
		std::unique_lock queue_lock (this -> queue_mutex);

		this -> input . push (response_delay);

		this -> output . push (request);
	}

	try
	{
		Thread::Timer::T round_trip_timer
		(
			this -> round_trip_timeout,
			Thread::Delay::T <Response>::cancel,
			& response_delay
		);
		return this -> response_delay . get ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Request timed out\n");
	}
}

template <typename Request, typename Response, typename Interface>
Response
T <Request, Response, Interface>::makeRequest (Request && request)
{
	Thread::Delay::T <Response> response_delay;

	{
		std::unique_lock queue_lock (this -> queue_mutex);

		this -> input . push (response_delay);

		this -> output . push (std::move (request));
	}

	try
	{
		Thread::Timer::T round_trip_timer
		(
			this -> round_trip_timeout,
			Thread::Delay::T <Response>::cancel,
			& response_delay
		);
		return this -> response_delay . get ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Request timed out\n");
	}
}

