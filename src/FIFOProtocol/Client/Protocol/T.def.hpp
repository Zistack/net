template <typename Request, typename Response, typename Interface>
template <typename ... Arguments>
T <Request, Response, Interface>::T
(
	std::chrono::milliseconds round_trip_timeout,
	Arguments &&... arguments
)
:	round_trip_timeout (round_trip_timeout),
	interface (std::forward <Arguments> (arguments) ...),
	input (this -> interface),
	output (this -> interface)
{
}
