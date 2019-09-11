T::T () : m_cancelled (false)
{
}

T::T (T && other)
:	m_cancelled (other . m_cancelled . load ()),
	m_signal (std::move (other . m_signal))
{
	other . m_cancelled = false;
}
