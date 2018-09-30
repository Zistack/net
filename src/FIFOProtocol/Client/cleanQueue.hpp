template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::cleanQueue ()
{
	try
	{
		while (true)
			response_queue.pop ()->set_exception (
			    std::make_exception_ptr (Failure::Error::T (
			        "Connection was closed before response was recieved\n")));
	}
	catch (Thread::ConcurrentQueue::End::T)
	{
	}
}
