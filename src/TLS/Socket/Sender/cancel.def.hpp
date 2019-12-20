template <typename Interface>
void
T <Interface>::cancel ()
{
	this -> m_cancel_signal . cancel ();
}
