template <typename Request, typename Response, typename Interface>
template <typename ... Arguments>
T <Request, Response, Interface>::T (Arguments && ... arguments)
:	interface (std::forward <Arguments> (arguments) ...),
	input (this -> interface, this -> output),
	output (this -> interface)
{
}
