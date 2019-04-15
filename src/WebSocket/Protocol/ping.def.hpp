template <typename Dispatcher>
void
T <Dispatcher>::ping (const std::vector <uint8_t> & payload)
{
	this -> output . ping (payload);
}
