template <template <typename> typename ClientService>
void
T <ClientService>::stop ()
{
	for (auto & connection : this -> m_connections) connection . stop ();
}
