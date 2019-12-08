template <typename Interface>
void
T <Interface>::cancelOutput ()
{
	this -> output () . cancel ();
}

template <typename Interface>
void
T <Interface>::cancelOutput (const CloseMessage::T & close_message)
{
	this -> output () . cancel (close_message);
}
