template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::run (
    IO::Interface::NonblockingInputStream::T * input_stream,
    IO::Interface::NonblockingOutputStream::T * output_stream)
{
	const std::string message_prefix = "IO::FIFOProtocol::Client::T::run\n";

	Failure::ExceptionStore::T exception_store;

	IO::Blocking::InputStream::T blocking_input_stream (
	    input_stream, &this->input_timeout_signal);
	IO::Blocking::OutputStream::T blocking_output_stream (
	    output_stream, &this->output_timeout_signal);
	this->output_stream = &blocking_output_stream;

	this->response_queue.open ();

	{
		Status::Scope::T (this->status_bit);

		Protocol::eventLoop (exception_store,
		    blocking_input_stream,
		    this->shutdown_signal,
		    [this, &blocking_input_stream]() {
			    this->event (blocking_input_stream);
		    });
	}

	this->response_queue.close ();

	this->cleanQueue ();

	try
	{
		exception_store.poll ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
