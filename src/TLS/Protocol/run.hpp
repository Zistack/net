void
T::run (IO::Interface::NonblockingInputStream::T * input_stream,
    IO::Interface::NonblockingOutputStream::T * output_stream)
{
	const std::string message_prefix = "TLS::Protocol::T::run\n";

	try
	{
		std::unique_ptr<ConnectableContext::T> context =
		    this->newContext (input_stream, output_stream);

		IO::Signal::T input_timeout_signal;
		IO::Pipe::T socket_to_protocol;
		IO::Blocking::OutputStream::T output_stream_to_protocol (
		    socket_to_protocol.output_stream, &input_timeout_signal);
		char input_buffer[T::BUF_SIZE];

		IO::Signal::T output_timeout_signal;
		IO::Pipe::T protocol_to_socket;
		IO::Interface::NonblockingInputStream::T * input_stream_from_protocol =
		    protocol_to_socket.input_stream;
		char output_buffer[T::BUF_SIZE];

		Failure::ExceptionStore::T exception_store;

		{
			Thread::Nursery::T nursery (&exception_store);

			nursery.add (
			    [this,
			        input_stream,
			        &context,
			        &input_buffer,
			        &output_stream_to_protocol,
			        &input_timeout_signal,
			        &socket_to_protocol]() {
				    this->input (input_stream,
				        *context,
				        input_buffer,
				        &output_stream_to_protocol,
				        input_timeout_signal);
				    socket_to_protocol.shutdown ();
			    },
			    [this]() { this->input_shutdown_signal.reset (); });

			nursery.add (
			    [this,
			        input_stream_from_protocol,
			        &output_buffer,
			        &context,
			        &output_timeout_signal]() {
				    this->output (input_stream_from_protocol,
				        output_buffer,
				        *context,
				        output_timeout_signal);
			    },
			    [this]() { this->output_shutdown_signal.reset (); });

			nursery.add (
			    [this, &socket_to_protocol, &protocol_to_socket]() {
				    this->protocol->run (socket_to_protocol.input_stream,
				        protocol_to_socket.output_stream);
				    this->input_shutdown_signal.reset ();
				    this->output_shutdown_signal.reset ();
			    },
			    [this]() { this->protocol->stop (); });
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

		exception_store.poll ();
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
