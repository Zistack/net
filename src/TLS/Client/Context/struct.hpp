struct T : TLS::ConfigurableContext::T, TLS::ConnectableContext::T
{
	T (IO::Interface::NonblockingInputStream::T * input,
	    IO::Interface::NonblockingOutputStream::T * output,
	    const Config::T & config,
	    IO::Signal::T & signal);

	~T () = default;

	private:
	void
	connect (const std::string & server_name, IO::Signal::T & signal);
};
