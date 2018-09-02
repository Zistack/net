template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::run (T<RequestType, ResponseType> * protocol)
{
	const std::string message_prefix =
	    "IO::FIFOProtocol::Server::Protocol::T::run\n";

	try
	{
		while (true)
		{
			std::promise<ResponseType> * promise =
			    protocol->response_queue.pop ();

			ResponseType response = promise->get_future ().get ();
			delete promise;

			{
				Thread::Timeout::T (protocol->output_timeout,
				    [&]() { protocol->output_timeout_signal->send (); });
				protocol->writeResponse (response, protocol->output_stream);
			}
			protocol->output_timeout_signal->recieve ();

			protocol->destroyResponse (response);
		}
	}
	catch (const Failure::End::T & e)
	{
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
