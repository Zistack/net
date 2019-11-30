template <typename Interface>
void
T <Interface>::cancel ()
{
	this -> m_output_queue . cancel ();
}
