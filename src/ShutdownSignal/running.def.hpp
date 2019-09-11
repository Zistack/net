bool
T::running ()
{
	return this -> m_state . load () == State::RUNNING;
}
