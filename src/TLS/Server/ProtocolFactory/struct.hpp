struct T : IO::Interface::ProtocolFactory::T
{
	T (IO::Interface::ProtocolFactory::T * protocol_factory,
	    std::chrono::milliseconds timeout,
	    Config::T & config);

	Connection::Protocol::T *
	make () override;

	~T () = default;

	IO::Interface::ProtocolFactory::T * protocol_factory;
	std::chrono::milliseconds timeout;

	Server::Context::T context;
};
