void
event ()
{
	const std::string message_prefix = "HTTP::Client::event\n";

	try
	{
		ResponsePromise::T * response_promise = this -> response_queue.pop ();

		Response::T * response = new Response (response_promise -> input_stream);

		response_promise -> put (response);
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
