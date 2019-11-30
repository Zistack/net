void
T::prime ()
{
	this -> MessageSender::T <SenderInterface::T>::prime ();
	this -> PingPongSender::T <SenderInterface::T>::prime ();

	this -> m_close_scope = Scope::T (this -> m_close_bit);
}
