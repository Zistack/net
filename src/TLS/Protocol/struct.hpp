struct T : IO::Interface::Protocol::T
{
	T (IO::Interface::Protocol::T & protocol,
	    std::chrono::milliseconds timeout);

	void
	prime (IO::Interface::NonblockingInputStream::T & input_stream,
	    IO::Interface::NonblockingOutputStream::T & output_stream) override;

	void
	run () override;

	void
	cancel () override;

	virtual ~T () override = default;

	protected:
	virtual std::unique_ptr<ConnectableContext::T>
	newContext (IO::Interface::NonblockingInputStream::T & input_stream,
	    IO::Interface::NonblockingOutputStream::T & output_stream) = 0;

	// Given members

	IO::Interface::Protocol::T & protocol;
	std::chrono::milliseconds timeout;

	private:
	void
	input (IO::Interface::NonblockingInputStream::T & input_stream,
	    ConnectableContext::T & context,
	    char * input_buffer,
	    IO::Blocking::OutputStream::T & output_stream_to_protocol);

	void
	output (IO::FileDescriptor::InputStream::T & input_stream_from_protocol,
	    char * output_buffer,
	    ConnectableContext::T & context);

	// Internal members

	IO::CancelSignal::T input_timeout_signal;
	IO::CancelSignal::T output_timeout_signal;

	static const int BUF_SIZE = 1024;

	char input_buffer[BUF_SIZE];
	char output_buffer[BUF_SIZE];

	Thread::SleepLock::T context_lock;
	bool spurious_read;

	Shutdown::Signal::T input_shutdown_signal;
	Shutdown::Signal::T output_shutdown_signal;

	Failure::ExceptionStore::T exception_store;

	// Transient members

	IO::Interface::NonblockingInputStream::T * input_stream;
	IO::Interface::NonblockingOutputStream::T * output_stream;

	std::unique_ptr<ConnectableContext::T> context;

	std::unique_ptr<IO::Pipe::T> socket_to_protocol;
	std::unique_ptr<IO::Pipe::T> protocol_to_socket;

	std::unique_ptr<IO::Blocking::OutputStream::T> output_stream_to_protocol;

	SuppressingScope::T<decltype (input_shutdown_signal)>
	    input_shutdown_signal_scope;
	SuppressingScope::T<decltype (output_shutdown_signal)>
	    output_shutdown_signal_scope;
};
