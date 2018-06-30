void
T::clean ()
{
	std::unique_lock lock (this -> mutex);

	this -> response_queue . close ();

	ResponsePromise::T * response_promise;

	while ((response_promise = this -> response_queue . pop ()))
	{
		response_promise.put (NULL);
	}

	this -> socket = NULL;
}
