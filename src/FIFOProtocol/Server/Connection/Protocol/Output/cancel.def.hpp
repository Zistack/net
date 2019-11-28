template <typename Interface, typename Response>
void
T <Interface, Response>::cancel ()
{
	this -> m_response_queue . cancel ();
}
