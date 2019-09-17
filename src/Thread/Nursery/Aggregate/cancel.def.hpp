template <typename ... Cancellables>
void
T <Cancellables ...>::cancel ()
{
	TypeTraits::map
	(
		[] (auto && thread) { thread . cancel (); },
		this -> m_threads
	);
}
