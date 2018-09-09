void
T::run ()
{
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

	exception_store.poll ();
}
