template <template <typename> typename ClientService>
void
T <ClientService>::setActive (size_t connection_index)
{
	this -> m_connections [connection_index] . setActive ();
}
