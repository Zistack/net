struct T
{
	void
	pong (std::vector <uint8_t> && payload);

	void
	dispatch (Message::T && message);
};
