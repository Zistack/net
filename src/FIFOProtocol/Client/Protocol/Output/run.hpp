template <typename RequestType>
void
T<RequestType>::run (
    IO::Interface::NonblockingOutputStream::T & nonblocking_output_stream)
{
	IO::CancelSignal::T output_cancel_signal;
	IO::Blocking::OutputStream::T output_stream (
	    nonblocking_output_stream, output_cancel_signal);

	try
	{
		while (true)
		{
			const RequestType & request = this->request_queue.pop ();

			try
			{
				{
					Failure::CancelScope::T output_cancel_scope;
					Thread::Timer::T (this->output_timeout,
					    &Failure::CancelScope::T::cancel,
					    &output_cancel_scope);
					writeRequest (request,
					    output_stream,
					    output_cancel_signal,
					    output_cancel_scope);
				}
				output_cancel_signal.clear ();
			}
			catch (Failure::CancelException::T)
			{
				throw Failure::ResourceError::T ("Writing request timed out\n");
			}
		}
	}
	catch (Failure::EndOfResource::T)
	{
	}
}
