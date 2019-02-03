void
T::listen (Thread::Nursery::T & nursery)
{
	Failure::ExceptionStore::T exception_store;

	{
		Socket::T server_socket (this->config);

		Protocol::eventLoop (exception_store,
		    server_socket,
		    this->shutdown_signal,
		    &T::accept,
		    server_socket,
		    nursery);
	}

	exception_store.poll ();
}
