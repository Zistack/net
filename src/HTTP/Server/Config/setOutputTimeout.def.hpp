void
T::setOutputTimeout (std::chrono::milliseconds output_timeout)
{
	this -> set <Spec::OUTPUT_TIMEOUT> (output_timeout . count ());
}
