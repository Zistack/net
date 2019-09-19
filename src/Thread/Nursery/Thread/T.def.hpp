template <typename Cancellable>
template <typename Function, typename ... Arguments>
T <Cancellable>::T
(
	Cancellable & cancellable,
	Function && function,
	Arguments && ... arguments
)
:	Base::T
	(
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	),
	m_cancellable (cancellable)
{
}

template <typename Cancellable>
T <Cancellable>::T (T && other)
:	Base::T (static_cast <Base::T &&> (other)),
	m_cancellable (other . m_cancellable),
	m_thread (std::move (other . m_thread))
{
}

template <typename Function, typename ... Arguments>
T <std::nullptr_t>::T
(
	std::nullptr_t,
	Function && function,
	Arguments && ... arguments
)
:	Base::T
	(
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	)
{
}
