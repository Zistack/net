void
T::setRoundTripTimeout (std::chrono::milliseconds round_trip_timeout)
{
	this -> set <Spec::ROUND_TRIP_TIMEOUT> (round_trip_timeout . count ());
}
