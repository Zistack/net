void
T::open ()
{
	this -> m_state . store (State::RUNNING);
}
