template <typename Interface, typename Request, typename Response>
void
T <Interface, Request, Response>::cancel ()
{
	this -> m_request_queue . cancel ();
}
