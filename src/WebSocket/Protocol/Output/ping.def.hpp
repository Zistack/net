void
T::ping (const std::vector <uint8_t> & payload)
{
	this -> ping_pong_sender . ping (payload);
}
