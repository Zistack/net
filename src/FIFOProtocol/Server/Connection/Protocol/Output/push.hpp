template <typename Response, typename Interface>
void
T<Response, Interface>::push (const Thread::Delay::T<Response> & response_delay)
{
	try
	{
		this->response_queue.push (response_delay);
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}
