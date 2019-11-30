template <typename Interface>
void
T <Interface>::cancel ()
{
	this -> m_input_shutdown_signal . cancel ();
}
