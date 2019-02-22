template <typename RequestType, typename ResponseType>
struct T : Failure::Cancellable::T
{
	T (std::chrono::milliseconds input_timeout);

	void
	prime ();

	void
	run (Protocol::T<RequestType, ResponseType> & protocol,
	    IO::Interface::NonblockingInputStream::T & nonblocking_input_stream);

	void
	cancel () override;

	void
	push (const ::Protocol::Delay::T<ResponseType> & response_delay);

	~T () = default;

	private:
	void
	event (Protocol::T<RequestType, ResponseType> & protocol,
	    IO::Blocking::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_cancel_signal);

	std::chrono::milliseconds input_timeout;

	Thread::ConcurrentQueue::T<::Protocol::Delay::T<ResponseType>>
	    response_queue;

	Failure::ExceptionStore::T exception_store;
	Shutdown::Signal::T input_shutdown_signal;

	SuppressingScope::T<Shutdown::Signal::T> input_shutdown_scope;
};
