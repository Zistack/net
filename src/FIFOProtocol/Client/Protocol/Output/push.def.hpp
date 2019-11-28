template <typename Interface, typename Request>
void
T <Interface, Request>::push (const Request & request)
{
	try
	{
		this -> m_request_queue . push (request);
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}

template <typename Interface, typename Request>
void
T <Interface, Request>::push (Request && request)
{
	try
	{
		this -> m_request_queue . push (std::move (request));
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}
