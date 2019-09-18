template <bool use_external_store, typename ... Cancellables>
T <use_external_store, Cancellables ...>::~T ()
{
	TypeTraits::map
	(
		[] (auto && thread) { thread . join (); },
		this -> m_threads
	);

	if constexpr (! use_external_store) this -> m_exception_store . poll ();
}
