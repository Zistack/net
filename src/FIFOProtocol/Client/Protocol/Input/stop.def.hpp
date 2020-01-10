template <typename Interface, typename Response>
void
T <Interface, Response>::stop ()
{
	this -> m_response_queue . close ();
}
