std::chrono::milliseconds
T::getInputTimeout () const
{
	return std::chrono::milliseconds (
	    this->get<GetConfig::UInt::Type::T> (Spec::T::INPUT_TIMEOUT).value ());
}
