void
T::run (ConnectionSocket & socket)
{
	IO::CancelSignal::T timeout_signal;

	try
	{
		Thread::Timer::T handshake_timer (
		    this->timeout, &IO::CancelSignal::T::cancel, &timeout_signal);
		{
			socket.handshake (timeout_signal);
		}
		timeout_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("TLS handshake timed out\n");
	}

	Failure::ExceptionStore::T exception_store;

	{
		IO::Pipe::T socket_to_protocol;
		IO::Pipe::T protocol_to_socket;

		SuppressingScope::T<Shutdown::Signal::T> input_scope (
		    this->input_shutdown_signal, exception_store);
		SuppressingScope::T<Shutdown::Signal::T> output_scope (
		    this->output_shutdown_singal, exception_store);

		Thread::Nursery::T nursery (exception_store);

		nursery.add (this->input_shutdown_signal,
		    [this, &socket, &socket_to_protocol]() {
			    this->input (socket, socket_to_protocol.outputStream ());
			    socket_to_protocol.shutdown ();
		    });

		nursery.add (this->output_shutdown_signal,
		    &T::output,
		    this,
		    protocol_to_socket.inputStream (),
		    socket);

		nursery.run (
		    this->protocol, [this, &socket_to_protocol, &protocol_to_socket]() {
			    this->protocol.run (socket_to_protocol.inputStream (),
			        protocol_to_socket.outputStream ());
			    this->input_shutdown_signal.cancel ();
			    this->output_shutdown_signal.cancel ();
		    });
	}

	try
	{
		{
			Thread::Timer::T close_timer (
			    this->timeout, &IO::CancelSignal::T::cancel, &timeout_signal);
			socket.close (timeout_signal);
		}
		timeout_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		exception_store.store (
		    Failure::ResourceError::T ("TLS close timed out\n"));
	}

	exception_store.poll ();
}
