struct T
{
	virtual void
	dispatch (const Protocol::T & protocol, Message::T & message) = 0;

	virtual void
	pong (const Protocol::T & protocol, IO::Vector::T & payload) = 0;
};
