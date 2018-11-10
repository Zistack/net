template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::run ()
{
	const std::string message_prefix = "IO::FIFOProtocol::Client::T::run\n";

	{
		Scope::T<decltype (this->response_queue)> response_queue_scope (
		    std::move (this->response_queue_scope));
		SuppressingScope::T<decltype (this->shutdown_signal)>
		    shutdown_signal_scope (std::move (this->shutdown_signal_scope));
		Scope::T<decltype (this->status_bit)> status_bit_scope (
		    std::move (this->status_bit_scope));

		nursery->run (
		    [this, &input_stream (*this->input_stream)]() {
			    ::Protocol::eventLoop (exception_store,
			        input_stream,
			        this->shutdown_signal,
			        [this, &input_stream]() { this->event (input_stream); });
		    },
		    [this]() { this->stop (); });
	}

	std::unique_ptr<IO::Blocking::InputStream::T> input_stream (
	    std::move (this->input_stream));
	std::unique_ptr<IO::Blocking::OutputStream::T> output_stream (
	    std::move (this->output_stream));

	std::unique_ptr<Thread::Nursery::T> nursery (std::move (this->nursery));

	try
	{
		this->exception_store.pop ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
