template <class RequestType, class ResponseType>
struct T : IO::Interface::Protocol::T
{
	T (std::chrono::milliseconds input_timeout,
	    std::chrono::milliseconds output_timeout);

	void
	prime (IO::Interface::NonblockingInputStream::T & input_stream,
	    IO::Interface::NonblockingOutputStream::T & output_stream) override;

	void
	run () override;

	void
	stop () override;

	virtual ~T () override = default;

	protected:
	virtual RequestType
	readRequest (IO::Blocking::InputStream::T & input_stream) = 0;

	virtual ResponseType
	map (RequestType request) = 0;

	virtual void
	writeResponse (ResponseType response,
	    IO::Blocking::OutputStream::T & output_stream) = 0;

	private:
	void
	input (IO::Blocking::InputStream::T & input_stream,
	    Thread::Nursery::T & nursery);

	void
	output (IO::Blocking::OutputStream::T & output_stream);

	void
	event (IO::Blocking::InputStream::T & input_stream,
	    Thread::Nursery::T & nursery);

	void
	computeResponse (RequestType request,
	    ::Protocol::Delay::T<ResponseType> response_delay);

	// Given members

	std::chrono::milliseconds input_timeout;
	std::chrono::milliseconds output_timeout;

	// Internal members

	IO::Signal::T input_timeout_signal;
	IO::Signal::T output_timeout_signal;

	::Protocol::DelayQueue::T<ResponseType> response_queue;
	Shutdown::Signal::T shutdown_signal;

	Failure::ExceptionStore::T exception_store;

	// Transient members

	std::unique_ptr<IO::Blocking::InputStream::T> input_stream;
	std::unique_ptr<IO::Blocking::OutputStream::T> output_stream;

	Scope::T<decltype (response_queue)> response_queue_scope;
	SuppressingScope::T<decltype (shutdown_signal)> shutdown_signal_scope;
};
