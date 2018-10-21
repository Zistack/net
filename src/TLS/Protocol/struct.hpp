struct T : IO::Interface::Protocol::T
{
	T (IO::Interface::Protocol::T * protocol,
	    std::chrono::milliseconds timeout);

	void
	run (IO::Interface::NonblockingInputStream::T * input_stream,
	    IO::Interface::NonblockingOutputStream::T * output_stream) override;

	void
	stop () override;

	virtual ~T () override = default;

	protected:
	virtual std::unique_ptr<ConnectableContext::T>
	newContext (IO::Interface::NonblockingInputStream::T * input_stream,
	    IO::Interface::NonblockingOutputStream::T * output_stream) = 0;

	IO::Interface::Protocol::T * protocol;
	std::chrono::milliseconds timeout;

	private:
	void
	input (IO::Interface::NonblockingInputStream::T * input_stream,
	    ConnectableContext::T & context,
	    char * input_buffer,
	    IO::Interface::OutputStream::T * output_stream_to_protocol,
	    IO::Signal::T & input_timeout_signal);

	void
	output (
	    IO::Interface::NonblockingInputStream::T * input_stream_from_protocol,
	    char * output_buffer,
	    ConnectableContext::T & context,
	    IO::Signal::T & output_timeout_signal);

	static const int BUF_SIZE = 1024;

	Thread::SleepLock::T context_lock;
	bool spurious_read;

	Shutdown::Signal::T input_shutdown_signal;
	Shutdown::Signal::T output_shutdown_signal;
};
