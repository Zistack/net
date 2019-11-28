template <typename Interface, typename Request, typename Response>
Response
T <Interface, Request, Response>::makeRequest (const Request & request)
{
	Thread::Delay::T <Response> response_delay;

	{
		std::unique_lock queue_lock (this -> m_queue_mutex);

		this -> input () . push (response_delay);

		this -> output () . push (request);
	}

	try
	{
		Thread::Timer::T round_trip_timer
		(
			this -> m_round_trip_timeout,
			[&] () { response_delay . cancel (); }
		);
		return response_delay . get ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Request timed out\n");
	}
}

template <typename Interface, typename Request, typename Response>
Response
T <Interface, Request, Response>::makeRequest (Request && request)
{
	Thread::Delay::T <Response> response_delay;

	{
		std::unique_lock queue_lock (this -> m_queue_mutex);

		this -> input () . push (response_delay);

		this -> output () . push (std::move (request));
	}

	try
	{
		Thread::Timer::T round_trip_timer
		(
			this -> m_round_trip_timeout,
			[&] () { response_delay . cancel (); }
		);
		return response_delay . get ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Request timed out\n");
	}
}
