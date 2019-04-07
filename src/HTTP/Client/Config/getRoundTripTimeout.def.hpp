std::chrono::milliseconds
T::getRoundTripTimeout () const
{
	return std::chrono::milliseconds
	(
		this -> get <Spec::ROUND_TRIP_TIMEOUT> ()
	);
}
