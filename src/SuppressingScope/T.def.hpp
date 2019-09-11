template <typename Scopable>
T <Scopable>::T () : m_scopable (nullptr), m_exception_store (nullptr)
{
}

template <typename Scopable>
template <typename ... Arguments>
T <Scopable>::T
(
	Scopable & scopable,
	Arguments && ... arguments,
	Failure::ExceptionStore::T & exception_store
)
:	m_scopable (& scopable),
	m_exception_store (& exception_store)
{
	scopable . open (std::forward <Arguments> (arguments) ...);
}

template <typename Scopable>
T <Scopable>::T (T && other)
:	m_scopable (other . m_scopable),
	m_exception_store (other . m_exception_store)
{
	other . m_scopable = nullptr;
	other . m_exception_store = nullptr;
}
