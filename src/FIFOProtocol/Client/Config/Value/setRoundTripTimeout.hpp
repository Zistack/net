void
T::setRoundTripTimeout (std::chrono::milliseconds round_trip_timeout)
{
	this->set<GetConfig::UInt::Type::T> (
	    Spec::T::ROUND_TRIP_TIMEOUT, round_trip_timeout.count ());
}
