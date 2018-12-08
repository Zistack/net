template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::output (
    IO::Blocking::OutputStream::T & output_stream)
{
	try
	{
		while (true)
		{
			ResponseType response = this->response_queue.pop ().get ();

			try
			{
				{
					Failure::CancelScope::T output_cancel_scope;
					Thread::Timer::T output_timer (
					    this->output_timeout, [&output_cancel_scope]() {
						    output_cancel_scope.cancel ();
					    });
					this->writeResponse (response,
					    output_stream,
					    this->output_cancel_signal,
					    output_cancel_scope);
				}
				this->output_cancel_signal.clear ();
			}
			catch (Failure::CancelException::T)
			{
				throw Failure::Error::T ("Writing response timed out\n");
			}
		}
	}
	catch (Failure::CancelException::T)
	{
	}
}
