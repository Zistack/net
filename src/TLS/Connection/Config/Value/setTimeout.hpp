void
T::setTimeout (uint64_t timeout)
{
	this->set<GetConfig::UInt::Type::T> (Spec::T::TIMEOUT, timeout);
}
