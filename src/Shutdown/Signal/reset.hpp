void
T::reset ()
{
	State::T expected = State::SET;

	if (this->state.compare_exchange_strong (expected, State::RESET))
	{
		this->signal.send ();
	}
}
