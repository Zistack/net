std::chrono::milliseconds
T::getOutputTimeout () const
{
	return std::chrono::milliseconds (
	    this->get<GetConfig::UInt::Type::T> (Spec::T::OUTPUT_TIMEOUT).value ());
}
