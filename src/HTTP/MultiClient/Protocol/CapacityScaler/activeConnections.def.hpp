template <typename Interface>
size_t
T <Interface>::activeConnections () const
{
	return this -> m_active_connections . load ();
}
