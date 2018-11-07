bool
T::running ()
{
	return this->state.load () == State::RUNNING;
}
