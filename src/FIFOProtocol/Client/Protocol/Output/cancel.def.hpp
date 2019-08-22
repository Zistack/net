template <typename Protocol, typename Request, typename Details>
void
T <Protocol, Request, Details>::cancel ()
{
	this -> m_request_queue . cancel ();
}
