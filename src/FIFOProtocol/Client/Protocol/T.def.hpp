template <typename Request, typename Response, typename Details>
template <typename ... Arguments>
T <Request, Response, Details>::T
(
	std::chrono::nanoseconds round_trip_timeout,
	Arguments &&... arguments
)
:	m_details (std::forward <Arguments> (arguments) ...),
	m_round_trip_timeout (round_trip_timeout)
{
}
