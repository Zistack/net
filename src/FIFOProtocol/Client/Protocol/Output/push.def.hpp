template <typename Protocol, typename Request, typename Details>
void
T <Protocol, Request, Details>::push (const Request & request)
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

template <typename Protocol, typename Request, typename Details>
void
T <Protocol, Request, Details>::push (Request && request)
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
