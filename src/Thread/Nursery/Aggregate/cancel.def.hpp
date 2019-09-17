template <bool use_external_store, typename ... Cancellables>
void
T <use_external_store, Cancellables ...>::cancel ()
{
	TypeTraits::map
	(
		[] (auto && thread) { thread . cancel (); },
		this -> m_threads
	);
}
