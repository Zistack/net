Response::T *
send (Request::T * request,
	Timer::Duration::T write_timeout,
	Timer::Duration::T read_timeout)
{
	const std::string message_prefix = "HTTP::Client::send\n";

	try
	{
		IO::Cancellable::InputStream::T <char> input_stream (this->socket->input_stream);
		IO::Cancellable::OutputStream::T <char> output_stream (this->socket->output_stream);

		ResponsePromise::T response_promise (& input_stream);

		std::unique_lock lock (this->mutex);

		{
			Timer timeout (write_timeout, [](){output_stream.cancel ();});
			request.writeTo (&output_stream);
		}

		response_queue.push (&response_promise);

		lock.unlock ();

		{
			Timer timeout (read_timeout, [](){input_stream.cancel ();});
			Response::T * response = response_promise.get ();
		}

		return response;
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
