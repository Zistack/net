struct T : FIFOProtocol::Server::Protocol::T<Request::T, Response::T>
{
	T (const Config::T & config, Responder::T & responder);

	~T () = default;

	private:
	std::unique_ptr<IO::Interface::Protocol::T>
	make () override;

	Config::T config;
	Responder::T & responder;
};
