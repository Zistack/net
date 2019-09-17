template <typename Cancellable>
template <typename Function, typename ... Arguments>
T <Cancellable>::T
(
	Cancellable && cancellable,
	Function && function,
	Arguments && ... arguments
)
:	m_cancellable (cancellable),
	m_thread
	(
		TypeTraits::launder <Function> (function),
		TypeTraits::launder <Arguments> (arguments) ...
	)
{
}

template <typename Function, typename ... Arguments>
T <std::nullptr_t>::T
(
	std::nullptr_t,
	Function && function,
	Arguments && ... arguments
)
:	m_thread
	(
		TypeTraits::launder <Function> (function),
		TypeTraits::launder <Arguments> (arguments) ...
	)
{
}
