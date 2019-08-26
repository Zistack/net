template <typename Output>
void
T <Output>::pong (const std::vector <uint8_t> & payload)
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
