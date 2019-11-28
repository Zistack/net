template <typename Interface, typename Request>
void
T <Interface, Request>::cancel ()
{
	this -> m_request_queue . cancel ();
}
