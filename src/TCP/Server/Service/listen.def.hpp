template <typename ServerProtocol>
void
T <ServerProtocol>::listen (Thread::Nursery::T & nursery)
{
	Failure::ExceptionStore::T exception_store;

	{
		Socket::T server_socket (this -> m_config);

		IO::Util::eventLoop
		(
			exception_store,
			server_socket,
			this -> m_shutdown_signal,
			& T::accept,
			server_socket,
			nursery
		);
	}

	exception_store . poll ();
}
