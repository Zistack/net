struct T : TLS::Protocol::T
{
	T (IO::Interface::Protocol::T & client_protcol,
	    std::chrono::milliseconds timeout,
	    Config::T & config);

	std::unique_ptr<ConnectableContext::T>
	newContext (IO::Interface::NonblockingInputStream::T & input_stream,
	    IO::Interface::NonblockingOutputStream::T & output_stream) override;

	~T () = default;

	private:
	Config::T & config;
};
