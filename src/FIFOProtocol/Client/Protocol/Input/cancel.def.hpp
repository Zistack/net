template <typename Protocol, typename Response, typename Details>
void
T <Protocol, Response, Details>::cancel ()
{
	this -> m_input_shutdown_signal . cancel ();
	this -> m_response_queue . cancel ();
}
