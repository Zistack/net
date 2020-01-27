template <template <typename> typename ClientService>
const T <ClientService> &
T <ClientService>::connectionManager () const
{
	return * this;
}

template <template <typename> typename ClientService>
T <ClientService> &
T <ClientService>::connectionManager ()
{
	return * this;
}
