void
T::output (IO::FileDescriptor::InputStream::T & input_stream_from_protocol,
    char * output_buffer,
    ConnectableContext::T & context)
{
	const std::string message_prefix = "TLS::Protocol::T::output\n";

	Failure::ExceptionStore::T exception_store;

	::Protocol::eventLoop (exception_store,
	    input_stream_from_protocol,
	    this->output_shutdown_signal,
	    [this, &input_stream_from_protocol, output_buffer, &context]() {
		    try
		    {
			    {
				    Thread::Timer::T output_timer (this->timeout,
				        [&]() { this->output_timeout_signal.send (); });

				    size_t num_bytes = input_stream_from_protocol.read (
				        output_buffer, T::BUF_SIZE);

				    std::unique_lock<decltype (this->context_lock)> lock (
				        this->context_lock);

				    this->spurious_read = context.write (
				        output_buffer, num_bytes, this->output_timeout_signal);
			    }
			    this->output_timeout_signal.recieve ();
		    }
		    catch (Failure::CancelException::T)
		    {
			    throw Failure::Error::T (
			        "Transfer from protocol to socket timed out\n");
		    }
	    });

	try
	{
		exception_store.poll ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
