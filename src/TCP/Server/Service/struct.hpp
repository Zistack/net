struct T : ::Socket::Server::Service::T
{
	T (IO::Interface::Server::Protocol::T & server_protocol,
	    const Config::T & config);

	~T () override = default;

	private:
	std::unique_ptr<IO::Interface::Server::Socket::T>
	newServerSocket () override;

	Config::T config;
};
