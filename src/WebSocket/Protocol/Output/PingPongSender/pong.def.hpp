template <typename Interface>
void
T <Interface>::pong (const std::vector <uint8_t> & payload)
{
	try
	{
		this -> m_output_queue . push ({Type::PONG, payload});
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}
