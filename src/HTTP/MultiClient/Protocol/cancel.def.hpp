template <template <typename> typename ClientService>
void
T <ClientService>::cancel ()
{
	this -> connectionManager () . cancel ();
	this -> capacityScaler () . cancel ();
}
