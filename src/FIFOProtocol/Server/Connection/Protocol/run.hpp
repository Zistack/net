template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::run ()
{
	const std::string message_prefix =
	    "IO::FIFOProtocol::Server::Protocol::T::run\n";

	{
		std::unique_ptr<IO::Blocking::InputStream::T> input_stream (
		    std::move (this->input_stream));
		std::unique_ptr<IO::Blocking::OutputStream::T> output_stream (
		    std::move (this->output_stream));

		Thread::Nursery::T nursery (this->exception_store);

		nursery.add (
		    [this,
		        &input_stream (*input_stream),
		        response_queue_scope (std::move (this->response_queue_scope)),
		        shutdown_signal_scope (std::move (this->shutdown_signal_scope)),
		        &nursery]() mutable { this->input (input_stream, nursery); },
		    [this]() { this->stop (); });

		nursery.run (
		    [this, &output_stream (*output_stream)]() {
			    this->output (output_stream);
		    },
		    [this]() { this->stop (); });
	}

	try
	{
		exception_store.pop ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
