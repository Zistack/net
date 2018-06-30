void
run ()
{
	const std::string message_prefix = "TCP::Client::run\n";

	try
	{
		EPoll::T epoll;

		epoll.add (this -> signal);
		epoll.add (this -> socket);

		this -> protocol -> init (this -> socket);

		Nursery::ExceptionStore::T exception_store;

		try this -> loop (& epoll);
		catch (Error::T e) exception_store.store (e);

		try this -> protocol -> clean ();
		catch (std::exception e) exception_store.store (e);

		try this -> socket.shutdown (IO::Socket::Direction::READ | IO::Socket::Direction::WRITE);
		catch (IO::Error::T e) exception_store.store (e);

		e.poll ();
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
	catch (Nursery::Error::T e) throw Error::T (message_prefix + e.what ());
}
