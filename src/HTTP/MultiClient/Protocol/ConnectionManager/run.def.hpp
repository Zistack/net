template <template <typename> typename ClientService>
void
T <ClientService>::run ()
{
	Thread::Nursery::Collection::T <false, Connection::T <ClientService>>
		nursery;

	for (auto & connection : this -> m_connections)
	{
		nursery . add (connection, [&] () { connection . run (); });
	}
}
