template <typename BufferedOutputStream>
template <typename ProxyBufferedOutputStream, typename>
T <BufferedOutputStream>::T
(
	BufferedOutputStream & output_stream,
	Failure::ExceptionStore::T & exception_store
)
:	m_output_stream (output_stream), m_exception_store (exception_store)
{
}
