void
T::clear ()
{
	if (this->state.exchange (State::CLEAR) == State::RESET)
	{
		IO::Util::wait (&this->signal);
		this->signal.recieve ();
	}
}
