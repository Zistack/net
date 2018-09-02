template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::cleanQueue ()
{
	try
	{
		while (true)
		{
			std::promise<ResponseType> * promise = this->response_queue.pop ();

			ResponseType response = promise->get_future ().get ();
			delete promise;

			this->destroyResponse (response);
		}
	}
	catch (const Failure::End::T & e)
	{
	}
}
