void
event ()
{
	const std::string message_prefix = "HTTP::Server::Connection::event\n";

	try
	{
		this -> exception_store.poll ();

		ResponsePromise::T * response_promise = new ResponsePromise ();

		response_queue.push (response_promise);

		IO::Cancellable::InputStream::T <char> input_stream (this -> socket -> input_stream);

		{
			Timer timeout (read_timeout, [](){input_stream.cancel ();});
			Request::T * request = new Request::T (& input_stream);
		}

		if (request -> method == "UPGRADE")
		{
			// Do a thing.  Or not.
		}

		this -> nursery.add (serve, response_promise, request);
	}
	catch (const BadMessageError::T& e)
	{
		response_promise.put
		(
			new Response::T ("400", this -> server -> uri, "1.1", {}, NULL)
		);
	}
	catch (const NotImplementedError::T& e)
	{
		response_promise.put
		(
			new Response::T ("501", this -> server -> uri, "1.1", {}, NULL)
		);
	}
	catch (IO::ResourceError::T& e)
	{
		response_promise.put
		(
			new Response::T ("500", this -> server -> uri, "1.1", {}, NULL)
		);

		throw e.set (message_prefix + e.what ());
	}
	catch (const IO::EncodingError::T& e)
	{
		response_promise.put
		(
			new Response::T ("400", this -> server -> uri, "1.1", {}, NULL)
		);

		throw e.set (message_prefix + e.what ());
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
