template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::cleanQueue ()
{
	try
	{
		while (true)
		{
			std::promise<ResponseType> * promise = this->response_queue.pop ();
			try
			{
				ResponseType response = promise->get_future ().get ();
				this->destroyResponse (response);
			}
			catch (...)
			{
			}
			delete promise;
		}
	}
	catch (Thread::ConcurrentQueue::End::T)
	{
	}
}
