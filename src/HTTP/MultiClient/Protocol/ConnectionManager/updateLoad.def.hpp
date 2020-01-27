template <template <typename> typename ClientService>
double
T <ClientService>::updateLoad (size_t connection_index)
{
	return this -> m_connections [connection_index] . updateLoad ();
}
