template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::run ()
{
	const std::string message_prefix =
	    "IO::FIFOProtocol::Server::Protocol::T::run\n";

	while (true)
	{
		std::promise<ResponseType> * promise = this->response_queue.pop ();

		ResponseType response = promise->get_future ().get ();
		delete promise;

		try
		{
			{
				Thread::Timer::T output_timer (this->output_timeout,
				    [this]() { this->output_timeout_signal->send (); });
				this->writeResponse (response, this->output_stream);
			}
			this->output_timeout_signal->recieve ();
		}
		catch (Failure::CancelException::T)
		{
			this->destroyResponse (response);
			throw Failure::Error::T (
			    message_prefix + "Writing response timed out\n");
		}
		catch (Failure::Error::T & e)
		{
			this->destroyResponse (response);
			throw e.set (message_prefix + e.what ());
		}

		this->destroyResponse (response);
	}
}
