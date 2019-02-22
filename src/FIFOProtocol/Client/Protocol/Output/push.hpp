template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::push (const RequestType & request)
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
