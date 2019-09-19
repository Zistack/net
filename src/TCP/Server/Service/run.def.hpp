template <typename ServerProtocol>
void
T <ServerProtocol>::run ()
{
	{
		SuppressingScope::T shutdown_scope
		(
			std::move (this -> m_shutdown_scope)
		);

		Socket::T server_socket (this -> m_config);

		Thread::Nursery::Collection::T <true, ConnectionProtocol> nursery
		(
			this -> m_exception_store
		);

		IO::Util::eventLoop
		(
			this -> m_exception_store,
			server_socket,
			this -> m_shutdown_signal,
			[&] () { this -> accept (server_socket, nursery); }
		);

		nursery . cancel ();
	}

	this -> m_exception_store . pop ();
}

