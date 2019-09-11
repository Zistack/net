template <typename Scopable>
T <Scopable>::T () : m_scopable (nullptr)
{
}

template <typename Scopable>
template <typename... Arguments>
T <Scopable>::T (Scopable & scopable, Arguments && ... arguments)
:	m_scopable (& scopable)
{
	scopable . open (std::forward <Arguments> (arguments) ...);
}

template <typename Scopable>
T <Scopable>::T (T && other) : m_scopable (other . m_scopable)
{
	other . m_scopable = nullptr;
}
