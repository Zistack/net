template <class RequestType, class ResponseType>
struct T : IO::Interface::Protocol::T
{
	T (std::chrono::milliseconds input_timeout,
	    std::chrono::milliseconds output_timeout,
	    std::chrono::milliseconds round_trip_timeout);

	void
	prime (IO::Interface::NonblockingInputStream::T & input_stream,
	    IO::Interface::NonblockingOutputStream::T & output_stream) override;

	void
	run () override;

	void
	cancel () override;

	ResponseType
	makeRequest (const RequestType & request);

	virtual ~T () override = default;

	protected:
	virtual void
	writeRequest (const RequestType & request,
	    IO::Blocking::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_cancel_signal,
	    Failure::CancelScope::T & cancel_scope) = 0;

	virtual ResponseType
	readResponse (IO::Blocking::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_cancel_signal,
	    Failure::CancelScope::T & cancel_scope) = 0;

	private:
	void
	event (IO::Blocking::InputStream::T & input_stream);

	// Given members

	std::chrono::milliseconds input_timeout;
	std::chrono::milliseconds output_timeout;
	std::chrono::milliseconds round_trip_timeout;

	// Internal members

	IO::CancelSignal::T input_cancel_signal;
	IO::CancelSignal::T output_cancel_signal;

	::Protocol::DelayQueue::T<ResponseType> response_queue;
	Shutdown::Signal::T shutdown_signal;

	Thread::SleepLock::T sleep_lock;
	Status::Bit::T<Thread::SleepLock::T> status_bit;

	Failure::ExceptionStore::T exception_store;

	// Transient members

	std::unique_ptr<IO::Blocking::InputStream::T> input_stream;
	std::unique_ptr<IO::Blocking::OutputStream::T> output_stream;

	std::unique_ptr<Thread::Nursery::T> nursery;

	Scope::T<decltype (response_queue)> response_queue_scope;
	SuppressingScope::T<decltype (shutdown_signal)> shutdown_signal_scope;
	Scope::T<decltype (status_bit)> status_bit_scope;
};
