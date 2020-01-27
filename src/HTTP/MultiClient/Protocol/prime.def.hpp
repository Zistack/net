template <template <typename> typename ClientService>
void
T <ClientService>::prime ()
{
	this -> connectionManager () . prime ();
	this -> capacityScaler () . prime ();
}
