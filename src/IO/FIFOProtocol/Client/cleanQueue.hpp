template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::cleanQueue ()
{
	try
	{
		while (true)
		{
			std::promise<ResponseType> * promise = response_queue.pop ();
			promise->set_exception (std::make_exception_ptr (
			    Failure::Error::T ("Error occured elsewhere in FIFO client")));
		}
	}
	catch (Thread::ConcurrentQueue::End::T)
	{
	}
}
