template <typename Cancellable>
T <Cancellable>::T (Cancellable cancellable)
:	m_cancellable (std::forward <Cancellable> (cancellable))
{
}

template <typename Cancellable>
T <Cancellable>::T (T && other)
:	Base::T (static_cast <Base::T &&> (other)),
	m_cancellable (std::forward <Cancellable> (other . m_cancellable))
{
}

T <std::nullptr_t>::T (std::nullptr_t)
{
}
