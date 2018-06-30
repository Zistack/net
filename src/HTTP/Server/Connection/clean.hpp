void
clean ()
{
	const std::string message_prefix = "HTTP::Server::Connection::clean\n";

	try
	{
		this -> response_queue . close ();

		ResponsePromise::T * response_promise;

		nursery.join ();

		this -> socket = NULL;
	}
	catch (Failure::Throwable::T& e)
	{
		this -> exception_store.store (e.set (message_prefix + e.what ()));
	}

	while ((response_promise = this -> response_queue.pop ()))
	{
		Response::T * response = response_promise.get ();
		delete response;
		delete response_promise;
	}

	this -> exception_store.poll ();
}
