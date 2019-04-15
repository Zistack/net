void
T::send (Message::T && message)
{
	try
	{
		this -> output_queue . push (std::move (message));
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}
