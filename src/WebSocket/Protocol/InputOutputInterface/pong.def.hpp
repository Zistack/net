template <typename Interface>
void
T <Interface>::pong (std::vector <uint8_t> && payload)
{
	this -> interface () . pong (std::move (payload));
}
