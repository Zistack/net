template <template <typename> typename ClientService>
void
T <ClientService>::run ()
{
	Thread::Nursery::Aggregate::T nursery
	(
		std::forward_as_tuple
		(
			this -> connectionManager (),
			[&] () { this -> connectionManager () . run (); }
		),
		std::forward_as_tuple
		(
			this -> capacityScaler (),
			[&] () { this -> capacityScaler () . run (); }
		)
	);
}
