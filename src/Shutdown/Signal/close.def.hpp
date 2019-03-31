void
T::close ()
{
	if (this -> state . exchange (State::INACTIVE) == State::SHUTTING_DOWN)
	{
		IO::Util::wait (this -> signal);
		this -> signal . recieve ();
	}
}
