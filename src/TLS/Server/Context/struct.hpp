struct T : TLS::ConfigurableContext::T
{
	T (const Config::T & config);

	std::unique_ptr<Connection::Context::T>
	accept (IO::Interface::NonblockingInputStream::T & input,
	    IO::Interface::NonblockingOutputStream::T & output,
	    IO::Signal::T & signal);

	~T () = default;

	private:
	struct tls *
	accept (IO::Interface::NonblockingInputStream::T & input,
	    IO::Interface::NonblockingOutputStream::T & output);

	friend Connection::Context::T;
};
