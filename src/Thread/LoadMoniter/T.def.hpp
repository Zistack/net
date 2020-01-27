T::T ()
:	m_on (false),
	m_last_reset (std::chrono::steady_clock::now ()),
	m_time_on_since_last_reset (0),
	m_load (0)
{
}
