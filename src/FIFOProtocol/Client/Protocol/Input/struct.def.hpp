template <typename Interface, typename Response>
struct T
{
	T () = default;

	void
	prime ();

	template <typename InputStream>
	void
	run (InputStream && input_stream);

	void
	cancel ();

	void
	push (const Thread::Delay::T <Response> & response_delay);

	const T &
	input () const;

	T &
	input ();

	~T () = default;

private:

	template <typename InputStream>
	void
	event (InputStream && input_stream);

	// Access to external members

	const Interface &
	interface () const;

	Interface &
	interface ();

	// Internal members

	Failure::ExceptionStore::T m_exception_store;
	ShutdownSignal::T m_input_shutdown_signal;

	Thread::ConcurrentQueue::T <Thread::Delay::T <Response>> m_response_queue;

	// Transient members

	SuppressingScope::T <ShutdownSignal::T> m_input_shutdown_scope;
	Scope::T <decltype (m_response_queue)> m_response_scope;
};
