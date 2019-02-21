std::chrono::milliseconds
T::getRoundTripTimeout () const
{
	return std::chrono::milliseconds (
	    this->get<GetConfig::UInt::Type::T> (Spec::T::ROUND_TRIP_TIMEOUT)
	        .value ());
}
