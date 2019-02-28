void
T::setCloseTimeout (std::chrono::milliseconds close_timeout)
{
	this->set<GetConfig::UInt::Type::T> (
	    Spec::T::CLOSE_TIMEOUT, close_timeout.count ());
}
