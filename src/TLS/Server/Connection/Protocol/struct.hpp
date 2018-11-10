struct T : TLS::Protocol::T
{
	T (std::unique_ptr<IO::Interface::Protocol::T> connection_protocol,
	    std::chrono::milliseconds timeout,
	    Server::Context::T & server_context);

	std::unique_ptr<ConnectableContext::T>
	newContext (IO::Interface::NonblockingInputStream::T & input_stream,
	    IO::Interface::NonblockingOutputStream::T & output_stream) override;

	~T () = default;

	std::unique_ptr<IO::Interface::Protocol::T> connection_protocol;
	Server::Context::T & server_context;
};
