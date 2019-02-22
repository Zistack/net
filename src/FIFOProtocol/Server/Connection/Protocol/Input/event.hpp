template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::event (
    Protocol::T<RequestType, ResponseType> & protocol,
    IO::Blocking::InputStream::T & input_stream,
    IO::CancelSignal::T & input_cancel_signal,
    Thread::Nursery::T & nursery)
{
	RequestType request;

	try
	{
		{
			Failure::CancelScope::T input_cancel_scope;
			Thread::Timer::T input_timer (this->input_timeout,
			    &Failure::CancelScope::T::cancel,
			    &input_cancel_scope);
			request = std::move (protocol.readRequest (
			    input_stream, input_cancel_signal, input_cancel_scope));
		}
		this->input_cancel_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::Error::T ("Reading request timed out\n");
	}

	::Protocol::Delay::T<ResponseType> response_delay;

	protocol.output.push (response_delay);

	nursery.add (
	    [this, request (std::move (request)), response_delay, &protocol]() {
		    this->respond (protocol, request, response_delay);
	    });
}
