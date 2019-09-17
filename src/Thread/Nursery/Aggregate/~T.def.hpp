template <bool use_external_store, typename ... Cancellables>
T <use_external_store, Cancellables ...>::~T ()
{
	TypeTraits::map
	(
		[] (auto && thread) { thread . join (); },
		this -> m_threads
	);
}
