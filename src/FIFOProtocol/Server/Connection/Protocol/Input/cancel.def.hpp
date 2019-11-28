template <typename Interface, typename Request, typename Response>
void
T <Interface, Request, Response>::cancel ()
{
	this -> m_input_shutdown_signal . cancel ();
}
