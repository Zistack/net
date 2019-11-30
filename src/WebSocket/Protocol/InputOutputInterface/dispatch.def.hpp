template <typename Interface>
void
T <Interface>::dispatch (Message::T && message)
{
	this -> interface () . dispatch (std::move (message));
}
