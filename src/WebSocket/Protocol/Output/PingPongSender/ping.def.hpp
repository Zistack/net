template <typename Output>
void
T <Output>::ping (const std::vector <uint8_t> & payload)
{
	try
	{
		this -> m_output_queue . push ({Type::PING, payload});
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::ServiceError::T ("Protocol is not running\n");
	}
}
