void
T::setInputTimeout (std::chrono::milliseconds input_timeout)
{
	this->set<GetConfig::UInt::Type::T> (
	    Spec::T::INPUT_TIMEOUT, input_timeout.count ());
}
