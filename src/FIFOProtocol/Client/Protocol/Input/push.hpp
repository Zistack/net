template <typename ResponseType>
void
T<ResponseType>::push (
    const ::Protocol::Delay::T<ResponseType> & response_delay)
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
