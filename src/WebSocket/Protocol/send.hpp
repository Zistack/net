void
T::send (std::unique_ptr<Message::T> && message)
{
	this->message_sender.send (std::move (message));
}
