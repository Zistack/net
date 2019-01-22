void
T::pong (const std::vector<uint8_t> & payload)
{
	this->ping_pong_sender.pong (payload);
}
