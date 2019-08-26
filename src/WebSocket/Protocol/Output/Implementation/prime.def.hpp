template <typename Protocol>
void
T <Protocol>::prime ()
{
	this -> messageSender () . prime ();
	this -> pingPongSender () . prime ();

	this -> m_close_scope = Scope::T (this -> m_close_bit);
}
