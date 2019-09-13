const GetConfig::Duration::T::Value &
T::roundTripTimeout () const
{
	return this -> value <Spec::ROUND_TRIP_TIMEOUT> ();
}

GetConfig::Duration::T::Value &
T::roundTripTimeout ()
{
	return this -> value <Spec::ROUND_TRIP_TIMEOUT> ();
}
