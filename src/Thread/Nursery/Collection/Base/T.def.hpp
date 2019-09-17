template <bool use_external_store, typename Cancellable>
T <use_external_store, Cancellable>::T () : m_cancelled (false)
{
}

template <bool use_external_store, typename Cancellable>
T <use_external_store, Cancellable>::T
(
	Failure::ExceptionStore::T & exception_store
)
:	ExceptionStore::T <use_external_store> (exception_store),
	m_cancelled (false)
{
}
