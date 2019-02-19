uint64_t
T::getTimeout () const
{
	return this->get<GetConfig::UInt::Type::T> (Spec::T::TIMEOUT).value ();
}
