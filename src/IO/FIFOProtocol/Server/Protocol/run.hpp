template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::run (T<RequestType, ResponseType> * protocol)
{
	const std::string message_prefix =
	    "IO::FIFOProtocol::Server::Protocol::T::run\n";

	while (true)
	{
		std::promise<ResponseType> * promise = protocol->response_queue.pop ();

		ResponseType response = promise->get_future ().get ();
		delete promise;

		try
		{
			{
				Thread::Timer::T output_timer (protocol->output_timeout,
				    [&]() { protocol->output_timeout_signal->send (); });
				protocol->writeResponse (response, protocol->output_stream);
			}
			protocol->output_timeout_signal->recieve ();
		}
		catch (Failure::CancelException::T)
		{
			throw Failure::Error::T (
			    message_prefix + "Writing response timed out\n");
		}
		catch (Failure::Error::T & e)
		{
			throw e.set (message_prefix + e.what ());
		}

		protocol->destroyResponse (response);
	}
}
