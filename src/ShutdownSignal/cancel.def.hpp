void
T::cancel ()
{
	State::T expected = State::RUNNING;

	if
	(
		this -> m_state . compare_exchange_strong
		(
			expected,
			State::SHUTTING_DOWN
		)
	)
	{
		this -> m_signal . send ();
	}
}
