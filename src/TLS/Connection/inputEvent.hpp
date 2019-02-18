void
T::inputEvent (ConnectionSocket::T & socket,
    char * input_buffer,
    IO::Interface::OutputStream::T & output_stream,
    IO::CancelSignal::T & input_timeout_signal)
{
	std::unique_lock<decltype (this->socket_mutex)> socket_lock (
	    this->socket_mutex);

	if (this->spurious_read)
	{
		this->spurious_read = false;
		return;
	}

	try
	{
		{
			Thread::Timer::T input_timer (this->timeout,
			    &IO::CancelSignal::T::cancel,
			    &input_timeout_signal);
			size_t num_bytes = socket.read (
			    input_buffer, this->buffer_size, input_timeout_signal);

			socket_lock.unlock ();

			output_stream.write (input_buffer, num_bytes);
		}
		input_timeout_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T (
		    "Transfer from socket to protocol timed out\n");
	}
}
