void
T::send (std::unique_ptr<Message::T> && message)
{
	this->output.send (std::move (message));
}
