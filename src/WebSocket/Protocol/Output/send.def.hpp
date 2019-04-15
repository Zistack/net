void
T::send (Message::T && message)
{
	this -> message_sender . send (std::move (message));
}
