void
T::setOutputTimeout (std::chrono::milliseconds output_timeout)
{
	this->set<GetConfig::UInt::Type::T> (
	    Spec::T::OUTPUT_TIMEOUT, output_timeout.count ());
}
