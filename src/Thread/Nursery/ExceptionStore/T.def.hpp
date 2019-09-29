T <false>::T ()
{
}

T <true>::T (Failure::ExceptionStore::T & exception_store)
:	m_exception_store (exception_store)
{
}
