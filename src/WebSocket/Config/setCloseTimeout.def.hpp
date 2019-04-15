void
T::setCloseTimeout (std::chrono::milliseconds close_timeout)
{
	this -> set <Spec::CLOSE_TIMEOUT> (close_timeout . count ());
}
