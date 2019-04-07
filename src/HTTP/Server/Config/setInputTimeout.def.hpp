void
T::setInputTimeout (std::chrono::milliseconds input_timeout)
{
	this -> set <Spec::INPUT_TIMEOUT> (input_timeout . count ());
}
