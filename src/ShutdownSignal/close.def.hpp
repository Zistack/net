void
T::close ()
{
	if (this -> m_state . exchange (State::INACTIVE) == State::SHUTTING_DOWN)
	{
		IO::Util::wait (this -> m_signal);
		this -> m_signal . recieve ();
	}
}
