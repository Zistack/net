template <template <typename> typename ClientService>
void
T <ClientService>::stop ()
{
	this -> connectionManager () . stop ();
	this -> capacityScaler () . stop ();
}
