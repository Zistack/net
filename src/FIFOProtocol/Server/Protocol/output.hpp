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
					Thread::Timer::T output_timer (this->output_timeout,
					    [this]() { this->output_timeout_signal.send (); });
					this->writeResponse (response, &output_stream);
				}
				this->output_timeout_signal.recieve ();
			}
			catch (Failure::CancelException::T)
			{
				this->destroyResponse (response);
				throw Failure::Error::T ("Writing response timed out\n");
			}
			this->destroyResponse (response);
		}
	}
	catch (Failure::CancelException::T)
	{
	}
}
