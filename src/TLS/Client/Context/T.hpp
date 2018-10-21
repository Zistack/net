T::T (IO::Interface::NonblockingInputStream::T * input,
    IO::Interface::NonblockingOutputStream::T * output,
    const Config::T & config,
    IO::Signal::T & signal) :
    TLS::Context::T (tls_client ()),
    TLS::ConnectableContext::T (input, output)
{
	this->configure (config);

	this->connect (config.serverName (), signal);
}
