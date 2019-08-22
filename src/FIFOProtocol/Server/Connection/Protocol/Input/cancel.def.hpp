template
<
	typename Protocol,
	typename Request,
	typename Response,
	typename Details
>
void
T <Protocol, Request, Response, Details>::cancel ()
{
	this -> m_input_shutdown_signal . cancel ();
}
