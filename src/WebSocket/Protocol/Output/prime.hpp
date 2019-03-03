void
T::prime ()
{
	message_sender.prime ();
	ping_pong_sender.prime ();

	this->close_scope = Scope::T<Status::Bit::T<std::mutex>> (this->close_bit);
}
