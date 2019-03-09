template <typename Request, typename Interface>
void
T<Request, Interface>::push (const Request & request)
{
	try
	{
		this->request_queue.push (request);
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}

template <typename Request, typename Interface>
void
T<Request, Interface>::push (Request && request)
{
	try
	{
		this->request_queue.push (std::move (request));
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}
