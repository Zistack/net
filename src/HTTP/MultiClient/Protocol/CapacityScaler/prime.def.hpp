template <typename Interface>
void
T <Interface>::prime ()
{
	this -> interface () . setActive (0);
	this -> m_active_connections . store (1);
}
