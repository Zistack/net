void
T::run ()
{
	const std::string message_prefix = "TCP::Server::run\n";

	try
	{
		IO::EPoll::T epoll;

		epoll.add (this -> signal);
		epoll.add (this -> server_socket);

		Nursery::ExceptionStore::T exception_store
		Nursery::T nursery (& exception_store);

		while (true)
		{
			IO::EPoll::Watchable::T * ready_stream = epoll.wait ();

			exception_store.poll ();

			if (ready_stream == this -> server_socket)
			{
				try Socket::T * socket = server_socket.accept ();
				catch (IO::Exception::T e)
				{
					log.print (e.what ());
					continue;
				}

				nursery.add (serve, this, socket);
			}
			else if (ready_stream == this -> signal)
			{
				break;
			}
		}

		Nursery.join ();
		exception_store.poll ();
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
	catch (Nursery::Error::T e) throw Error::T (message_refix + e.what ());
}
