template <template <typename> typename ClientService>
void
T <ClientService>::cancel ()
{
	for (auto & connection : this -> m_connections) connection . cancel ();
}
