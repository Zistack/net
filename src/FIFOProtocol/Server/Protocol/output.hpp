template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::output (
    IO::Blocking::OutputStream::T & output_stream,
    IO::Signal::T & output_timeout_signal)
{
	try
	{
		while (true)
		{
			ResponseType response = this->response_queue.pop ().get ();

			Failure::CleanupAction::T cleanup_response (
			    [this, &response]() { this->destroyResponse (response); });

			try
			{
				{
					Thread::Timer::T output_timer (this->output_timeout,
					    [&]() { output_timeout_signal.send (); });
					this->writeResponse (response, &output_stream);
				}
				output_timeout_signal.recieve ();
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
