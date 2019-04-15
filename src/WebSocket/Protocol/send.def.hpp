template <typename Dispatcher>
void
T <Dispatcher>::send (Message::T && message)
{
	this -> output . send (std::move (message));
}
