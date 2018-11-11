struct T : IO::Interface::Server::Protocol::T
{
	T (IO::Interface::Server::Protocol::T & server_protocol,
	    std::chrono::milliseconds timeout,
	    Config::T & config);

	std::unique_ptr<IO::Interface::Protocol::T>
	make () override;

	~T () = default;

	private:
	IO::Interface::Server::Protocol::T & server_protocol;
	std::chrono::milliseconds timeout;

	Server::Context::T context;
};
