template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::run (
    Protocol::T<RequestType, ResponseType> & protocol,
    IO::Interface::NonblockingOutputStream::T & nonblocking_output_stream)
{
	Scope::T<decltype (this->response_queue)> response_scope (
	    std::move (this->response_scope));

	IO::CancelSignal::T output_cancel_signal;
	IO::Blocking::OutputStream::T output_stream (
	    nonblocking_output_stream, output_cancel_signal);

	try
	{
		while (true)
		{
			ResponseType response =
			    std::move (this->response_queue.pop ().get ());

			try
			{
				{
					Failure::CancelScope::T output_cancel_scope;
					Thread::Timer::T output_timer (this->output_timeout,
					    &Failure::CancelScope::T::cancel,
					    &output_cancel_scope);
					protocol.writeResponse (response,
					    output_stream,
					    output_cancel_signal,
					    output_cancel_scope);
				}
				output_cancel_signal.clear ();
			}
			catch (Failure::CancelException::T)
			{
				throw Failure::Error::T ("Writing response timed out\n");
			}
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
