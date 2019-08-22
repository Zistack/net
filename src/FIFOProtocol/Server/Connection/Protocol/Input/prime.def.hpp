template
<
	typename Protocol,
	typename Request,
	typename Response,
	typename Details
>
void
T <Protocol, Request, Response, Details>::prime ()
{
	this -> m_input_shutdown_scope = SuppressingScope::T
	(
		this -> m_input_shutdown_signal,
		this -> m_exception_store
	);
}
