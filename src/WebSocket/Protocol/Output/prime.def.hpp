void
T::prime ()
{
	message_sender . prime ();
	ping_pong_sender . prime ();

	this -> close_scope = Scope::T (this -> close_bit);
}
