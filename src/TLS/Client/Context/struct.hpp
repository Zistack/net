struct T : TLS::ConfigurableContext::T, TLS::ConnectableContext::T
{
	T (IO::Interface::NonblockingInputStream::T & input,
	    IO::Interface::NonblockingOutputStream::T & output,
	    const Config::T & config);

	void
	connect (IO::Signal::T & signal) override;

	~T () = default;

	private:
	const Config::T & config;
};
