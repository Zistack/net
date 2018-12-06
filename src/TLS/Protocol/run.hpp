void
T::run ()
{
	const std::string message_prefix = "TLS::Protocol::T::run\n";

	IO::Interface::NonblockingInputStream::T & input_stream =
	    *this->input_stream;
	// IO::Interface::NonblockingOutputStream::T & output_stream =
	//     *this->output_stream;
	this->input_stream = nullptr;
	this->output_stream = nullptr;

	std::unique_ptr<ConnectableContext::T> context (std::move (this->context));

	{
		std::unique_ptr<IO::Pipe::T> socket_to_protocol (
		    std::move (this->socket_to_protocol));
		std::unique_ptr<IO::Pipe::T> protocol_to_socket (
		    std::move (this->protocol_to_socket));

		IO::FileDescriptor::InputStream::T & input_stream_from_protocol =
		    protocol_to_socket->inputStream ();
		std::unique_ptr<IO::Blocking::OutputStream::T>
		    output_stream_to_protocol (
		        std::move (this->output_stream_to_protocol));

		SuppressingScope::T<decltype (this->input_shutdown_signal)>
		    input_shutdown_signal_scope (
		        std::move (this->input_shutdown_signal_scope));
		SuppressingScope::T<decltype (this->output_shutdown_signal)>
		    output_shutdown_signal_scope (
		        std::move (this->output_shutdown_signal_scope));

		Thread::Nursery::T nursery (this->exception_store);

		nursery.add (
		    [this,
		        &input_stream,
		        &context (*context),
		        &output_stream_to_protocol (*output_stream_to_protocol),
		        &socket_to_protocol (*socket_to_protocol)]() {
			    this->input (input_stream,
			        context,
			        input_buffer,
			        output_stream_to_protocol);
			    socket_to_protocol.shutdown ();
		    },
		    &this->input_shutdown_signal);

		nursery.add (
		    [this, &context (*context), &input_stream_from_protocol]() {
			    this->output (
			        input_stream_from_protocol, output_buffer, context);
		    },
		    &this->output_shutdown_signal);

		nursery.run (
		    [this]() {
			    this->protocol.run ();
			    this->input_shutdown_signal.cancel ();
			    this->output_shutdown_signal.cancel ();
		    },
		    &this->protocol);
	}

	// This should probably be done in the destructor of the context object.
	try
	{
		IO::Signal::T close_timeout_signal;
		Thread::Timer::T close_timer (
		    this->timeout, [&]() { close_timeout_signal.send (); });
		context->close (close_timeout_signal);
	}
	catch (Failure::CancelException::T)
	{
		exception_store.store (Failure::Error::T ("Close timed out\n"));
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
