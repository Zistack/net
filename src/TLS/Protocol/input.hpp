void
T::input (IO::Interface::NonblockingInputStream::T & input_stream,
    ConnectableContext::T & context,
    char * input_buffer,
    IO::Blocking::OutputStream::T & output_stream_to_protocol)
{
	const std::string message_prefix = "TLS::Protocol::T::input\n";

	Failure::ExceptionStore::T exception_store;

	::Protocol::eventLoop (exception_store,
	    input_stream,
	    this->input_shutdown_signal,
	    [this, &context, input_buffer, &output_stream_to_protocol]() {
		    std::unique_lock<decltype (this->context_lock)> lock (
		        this->context_lock);

		    if (this->spurious_read)
		    {
			    this->spurious_read = false;
			    return;
		    }

		    try
		    {
			    {
				    Thread::Timer::T input_timer (this->timeout,
				        [&]() { this->input_timeout_signal.cancel (); });

				    size_t num_bytes = context.read (
				        input_buffer, T::BUF_SIZE, this->input_timeout_signal);

				    lock.unlock ();

				    output_stream_to_protocol.write (input_buffer, num_bytes);
			    }
			    this->input_timeout_signal.clear ();
		    }
		    catch (Failure::CancelException::T)
		    {
			    throw Failure::Error::T (
			        "Transfer from socket to protocol timed out\n");
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
