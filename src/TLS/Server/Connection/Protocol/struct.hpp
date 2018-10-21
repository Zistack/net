struct T : TLS::Protocol::T
{
	T (IO::Interface::Protocol::T * protcol,
	    std::chrono::milliseconds timeout,
	    Server::Context::T & server_context);

	std::unique_ptr<ConnectableContext::T>
	newContext (IO::Interface::NonblockingInputStream::T * input_stream,
	    IO::Interface::NonblockingOutputStream::T * output_stream) override;

	~T ();

	Server::Context::T & server_context;
};
