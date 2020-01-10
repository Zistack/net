template <typename Interface, typename Request, typename Response>
void
T <Interface, Request, Response>::push
(
	const Request & request,
	const Thread::Delay::T <Response> & response_delay
)
{
	try
	{
		this -> m_request_queue . push
		(
			std::make_pair (request, response_delay)
		);
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}

template <typename Interface, typename Request, typename Response>
void
T <Interface, Request, Response>::push
(
	Request && request,
	const Thread::Delay::T <Response> & response_delay
)
{
	try
	{
		this -> m_request_queue . push
		(
			std::make_pair (std::move (request), response_delay)
		);
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}
