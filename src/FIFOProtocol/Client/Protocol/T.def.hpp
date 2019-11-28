template <typename Interface, typename Request, typename Response>
T <Interface, Request, Response>::T
(
	std::chrono::nanoseconds round_trip_timeout
)
:	m_round_trip_timeout (round_trip_timeout)
{
}
