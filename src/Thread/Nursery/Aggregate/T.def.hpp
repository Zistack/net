template <bool use_external_store, typename ... Cancellables>
template <typename ... ArgumentPacks>
T <use_external_store, Cancellables ...>::T
(
	ArgumentPacks && ... argument_packs
)
:	m_threads (std::forward <Cancellables> (std::get <0> (argument_packs)) ...)
{
	this -> init (std::forward <ArgumentPacks> (argument_packs) ...);
}

template <bool use_external_store, typename ... Cancellables>
template <typename ... ArgumentPacks>
T <use_external_store, Cancellables ...>::T
(
	Failure::ExceptionStore::T & exception_store,
	ArgumentPacks && ... argument_packs
)
:	ExceptionStore::T <use_external_store> (exception_store),
	m_threads (std::forward <Cancellables> (std::get <0> (argument_packs)) ...)
{
	this -> init (std::forward <ArgumentPacks> (argument_packs) ...);
}
