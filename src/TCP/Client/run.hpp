void
T::run ()
{
	const std::string message_prefix = "TCP::Client::T::run\n";

	Failure::ExceptionStore::T exception_store;

	IO::Util::runProtocol (this->protocol,
	    exception_store,
	    this->socket->input_stream,
	    this->socket->output_stream,
	    this->signal);

	try
	{
		this->socket->shutdown (
		    IO::Socket::Direction::READ | IO::Socket::Direction::WRITE);
	}
	catch (...)
	{
		exception_store.store (std::current_exception ());
	}

	try
	{
		exception_store.poll ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
