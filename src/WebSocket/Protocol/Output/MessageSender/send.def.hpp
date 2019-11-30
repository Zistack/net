template <typename Interface>
void
T <Interface>::send (Message::T && message)
{
	try
	{
		this -> m_output_queue . push (std::move (message));
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}
