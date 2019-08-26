template <typename Protocol, typename Dispatcher>
void
T <Protocol, Dispatcher>::cancel ()
{
	this -> m_input_shutdown_signal . cancel ();
}
