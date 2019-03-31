void
T::cancel ()
{
	State::T expected = State::RUNNING;

	if
	(
		this -> state . compare_exchange_strong (expected, State::SHUTTING_DOWN)
	)
	{
		this -> signal . send ();
	}
}
