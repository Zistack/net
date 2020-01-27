template <typename Interface>
void
T <Interface>::cancel ()
{
	this -> m_active_connections . store (0);

	this -> m_active_condition_variable . notify_one ();
}
