struct T : FIFOProtocol::Server::Protocol::T<Request::T, Response::T>
{
	T (std::chrono::milliseconds input_timeout,
	    std::chrono::milliseconds output_timeout,
	    Responder::T & responder);

	~T () = default;

	private:
	std::unique_ptr<IO::Interface::Protocol::T>
	make () override;

	Responder::T & responder;
};
