template <typename ... Arguments, typename>
T::T (Arguments && ... arguments)
:	SimpleClientInterface::T (std::forward <Arguments> (arguments) ...),
	running (false),
	active (false),
	primed (false)
{
}
