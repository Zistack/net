struct T : ::Socket::Client::Service::T
{
	T (IO::Interface::Protocol::T & client_protocol, const Config::T & config);

	~T () override = default;

	private:
	std::unique_ptr<IO::Interface::Socket::T>
	newSocket () override;

	Config::T config;
};
