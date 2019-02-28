std::chrono::milliseconds
T::getCloseTimeout () const
{
	return std::chrono::milliseconds (
	    this->get<GetConfig::UInt::Type::T> (Spec::T::CLOSE_TIMEOUT).value ());
}
