template <typename Cancellable>
T <Cancellable>::T (size_t size)
:	m_cancellables (new Cancellable * [size]),
	m_next (0)
{
}
