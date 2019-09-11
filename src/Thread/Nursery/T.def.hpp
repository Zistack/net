T::T () noexcept
:	m_cancelled (false),
	m_internal_store (std::make_unique <Failure::ExceptionStore::T> ()),
	m_exception_store (* m_internal_store)
{
}

T::T (Failure::ExceptionStore::T & exception_store) noexcept
:	m_cancelled (false),
	m_exception_store (exception_store)
{
}
