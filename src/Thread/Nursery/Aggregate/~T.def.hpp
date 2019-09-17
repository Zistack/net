template <typename ... Cancellables>
T <Cancellables ...>::~T ()
{
	TypeTraits::map
	(
		[] (auto && thread) { thread . join (); },
		this -> m_threads
	);
}
