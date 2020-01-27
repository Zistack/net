template <template <typename> typename ClientService>
void
T <ClientService>::prime ()
{
	for (auto & connection : this -> m_connections) connection . prime ();
}
