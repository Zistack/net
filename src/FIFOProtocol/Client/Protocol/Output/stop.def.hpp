template <typename Interface, typename Request, typename Response>
void
T <Interface, Request, Response>::stop ()
{
	this -> m_request_queue . close ();
}
