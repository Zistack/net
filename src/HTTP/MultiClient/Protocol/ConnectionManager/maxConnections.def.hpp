template <template <typename> typename ClientService>
size_t
T <ClientService>::maxConnections () const
{
	return this -> m_connections . size ();
}
