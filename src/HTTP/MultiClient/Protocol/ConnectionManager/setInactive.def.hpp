template <template <typename> typename ClientService>
void
T <ClientService>::setInactive (size_t connection_index)
{
	this -> m_connections [connection_index] . setInactive ();
}
