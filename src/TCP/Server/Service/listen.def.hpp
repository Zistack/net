template <typename ServerProtocol>
void
T <ServerProtocol>::listen (Thread::Nursery::T & nursery)
{
	Failure::ExceptionStore::T exception_store;

	{
		Socket::T server_socket (this -> config);

		IO::Util::eventLoop
		(
			exception_store,
			server_socket,
			this -> shutdown_signal,
			& T::accept,
			server_socket,
			nursery
		);
	}

	exception_store . poll ();
}