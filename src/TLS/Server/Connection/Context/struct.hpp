struct T : TLS::ConnectableContext::T
{
	T (Server::Context::T & server_context,
	    IO::Interface::NonblockingInputStream::T * input,
	    IO::Interface::NonblockingOutputStream::T * output,
	    IO::Signal::T & signal);

	~T () = default;
};
