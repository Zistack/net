template <typename RequestType, typename ResponseType>
ResponseType
T<RequestType, ResponseType>::makeRequest (const RequestType & request)
{
	::Protocol::Delay::T<ResponseType> response_delay;

	{
		std::unique_lock<decltype (this->mutex)> queue_lock (this->mutex);

		this->input.push (response_delay);

		this->output.push (request);
	}

	try
	{
		Thread::Timer::T (this->round_trip_timeout,
		    &::Protocol::Delay::T<ResponseType>::cancel,
		    &response_delay);
		return this->response_delay.get ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("Request timed out\n");
	}
}
