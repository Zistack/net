template <typename Cancellable>
template <typename Function, typename ... Arguments>
void
T <Cancellable>::add
(
	Cancellable cancellable,
	Function && function,
	Arguments && ... arguments
)
{
	this -> Base::T <Cancellable>::add
	(
		cancellable,
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);
}

template <typename Function, typename ... Arguments>
void
T <std::nullptr_t>::add
(
	Function && function,
	Arguments && ... arguments
)
{
	this -> Base::T <std::nullptr_t>::add
	(
		nullptr,
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);
}
