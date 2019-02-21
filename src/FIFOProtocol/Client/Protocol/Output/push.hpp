template <typename RequestType>
void
T<RequestType>::push (const RequestType & request)
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
