template <typename Response, typename Interface>
template <typename OutputStream>
void
T<Response, Interface>::run (OutputStream && output_stream)
{
	Scope::T<decltype (this->response_queue)> response_scope (
	    std::move (this->response_scope));

	try
	{
		while (true)
		{
			this->interface.writeResponse (this->response_queue.pop ().get (),
			    std::forward<OutputStream> (output_stream));
		}
	}
	catch (Failure::EndOfResource::T)
	{
		// This happens when the queue is closed.
	}
	catch (Failure::CancelException::T)
	{
		// This happens when an error occurs while computing a response for a
		// request.  That error will be reported elsewhere.
	}
}
