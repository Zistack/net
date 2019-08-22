template <typename Protocol, typename Response, typename Details>
void
T <Protocol, Response, Details>::push
(
	const Thread::Delay::T <Response> & response_delay
)
{
	try
	{
		this -> m_response_queue . push (response_delay);
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}
