template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::run (
    IO::Interface::NonblockingInputStream::T * input_stream,
    IO::Interface::NonblockingOutputStream::T * output_stream)
{
	const std::string message_prefix =
	    "IO::FIFOProtocol::Server::Protocol::T::run\n";

	Failure::ExceptionStore::T exception_store;

	IO::Signal::T input_timeout_signal;
	IO::Blocking::InputStream::T blocking_input_stream (
	    input_stream, &input_timeout_signal);

	IO::Signal::T output_timeout_signal;
	IO::Blocking::OutputStream::T blocking_output_stream (
	    output_stream, &output_timeout_signal);

	{
		::Protocol::DelayQueue::Scope::T<ResponseType> response_period (
		    this->response_queue);

		Thread::Nursery::T nursery (&exception_store);

		nursery.add (
		    [this, &blocking_output_stream, &output_timeout_signal]() {
			    this->output (blocking_output_stream, output_timeout_signal);
		    },
		    [this]() { this->response_queue.cancel (); });

		nursery.add (
		    [this,
		        &exception_store,
		        &blocking_input_stream,
		        &input_timeout_signal,
		        &nursery]() {
			    ::Protocol::eventLoop (exception_store,
			        &blocking_input_stream,
			        this->shutdown_signal,
			        [this,
			            &blocking_input_stream,
			            &input_timeout_signal,
			            &nursery]() {
				        this->event (blocking_input_stream,
				            input_timeout_signal,
				            nursery);
			        });
			    exception_store.poll ();
			    this->stop ();
		    },
		    [this]() { this->shutdown_signal.reset (); });
	}

	try
	{
		exception_store.poll ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
