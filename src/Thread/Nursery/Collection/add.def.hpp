template <bool use_external_store, typename Cancellable>
template <typename Function, typename ... Arguments>
void
T <use_external_store, Cancellable>::add
(
	Cancellable cancellable,
	Function && function,
	Arguments && ... arguments
)
{
	this -> Base::T <use_external_store, Cancellable>::add
	(
		cancellable,
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);
}

template <bool use_external_store>
template <typename Function, typename ... Arguments>
void
T <use_external_store, std::nullptr_t>::add
(
	Function && function,
	Arguments && ... arguments
)
{
	this -> Base::T <use_external_store, std::nullptr_t>::add
	(
		nullptr,
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);
}
