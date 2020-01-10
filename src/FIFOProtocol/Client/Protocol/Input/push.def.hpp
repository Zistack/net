template <typename Interface, typename Response>
void
T <Interface, Response>::push
(
	const Thread::Delay::T <Response> & response_delay
)
{
	try
	{
		if constexpr (HooksLoadEvents::HasQueueActive::T <Interface>::value)
		{
			this -> m_response_queue . push
			(
				response_delay,
				[&] () { this -> interface () . queueActive (); }
			);
		}
		else this -> m_response_queue . push (response_delay);
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}
