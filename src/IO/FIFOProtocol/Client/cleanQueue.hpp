template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::cleanQueue ()
{
	try
	{
		while (true) response_queue.pop ();
	}
	catch (Thread::ConcurrentQueue::End::T)
	{
	}
}
