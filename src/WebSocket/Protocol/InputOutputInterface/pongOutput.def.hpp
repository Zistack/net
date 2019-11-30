template <typename Interface>
void
T <Interface>::pongOutput (const std::vector <uint8_t> & payload)
{
	this -> output () . pong (payload);
}
