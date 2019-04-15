template <typename Dispatcher>
void
T <Dispatcher>::pong (const std::vector <uint8_t> & payload)
{
	this -> output . pong (payload);
}
