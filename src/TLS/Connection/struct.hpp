struct T : Failure::Cancellable::T
{
	T (IO::Interface::Protocol::T & protocol,
	    std::chrono::milliseconds timeout);

	void
	prime ();

	void
	run (ConnectionSocket::T & socket);

	void
	cancel () override;

	~T () = default;

	protected:
	// Given members

	IO::Interface::Protocol::T & protocol;

	std::chrono::milliseconds timeout;
	size_t buffer_size;

	private:
	void
	input (ConnectionSocket::T & socket,
	    IO::Interface::NonblockingOutputStream::T & output_stream);

	void
	inputEvent (ConnectionSocket::T & socket,
	    char * input_buffer,
	    IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & input_timeout_signal);

	void
	output (IO::Interface::NonblockingInputStream::T & input_stream,
	    ConnectionSocket::T & socket);

	void
	outputEvent (IO::Interface::InputStream::T & input_stream,
	    char * output_buffer,
	    ConnectionSocket::T & socket,
	    IO::CancelSignal::T & output_timeout_signal);

	// Internal members

	Thread::SleepMutex::T socket_mutex;
	bool spurious_read;

	Shutdown::Signal::T input_shutdown_signal;
	Shutdown::Signal::T output_shutdown_signal;
};
