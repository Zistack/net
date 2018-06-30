void send ()
{
	const std::string message_prefix = "HTTP::Server::Connection::send\n";

	try
	{
		ResponsePromise::T * response_promise;

		while ((response_promise = this -> response_queue.pop ()))
		{
			Response::T * response = response_promise.get ();

			delete response_promise;

			IO::Cancellable::OutputStream::T <char> output_stream (
				this -> socket -> output_stream
			);

			{
				Timer timeout (this -> write_timeout, [](){output_stream.cancel ();});
				try response -> writeTo (& output_stream);
				catch (... e)
				{
					delete response;
					throw e;
				}
			}

			delete response;
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
