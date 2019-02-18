void
T::outputEvent (IO::Interface::NonblockingInputStream::T & input_stream,
    char * output_buffer,
    ConnectionSocket::T & socket,
    IO::CancelSignal::T & output_timeout_signal)
{
	try
	{
		{
			Thread::Timer::T output_timer (this->timeout,
			    &IO::CancelSignal::T::cancel,
			    &output_timeout_signal);

			size_t num_bytes;

			while (!(num_bytes =
			             input_stream.read (output_buffer, this->buffer_size)))
				;

			std::unique_lock<decltype (this->socket_mutex)> socket_lock (
			    this->socket_mutex);

			this->spurious_read =
			    socket.write (output_buffer, num_bytes, output_timeout_signal);
		}
		output_timeout_signal.clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T (
		    "Transfer from protocol to socket timed out\n");
	}
}
