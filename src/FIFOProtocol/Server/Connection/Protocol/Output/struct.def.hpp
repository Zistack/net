template <typename Interface, typename Response>
struct T
{
	T () = default;

	void
	prime ();

	template <typename OutputStream>
	void
	run (OutputStream && output_stream);

	void
	cancel ();

	void
	push (const Thread::Delay::T <Response> & response_delay);

	const T &
	output () const;

	T &
	output ();

	~T () = default;

private:

	// Access to external members

	const Interface &
	interface () const;

	Interface &
	interface ();

	// Internal members

	Thread::ConcurrentQueue::T <Thread::Delay::T <Response>> m_response_queue;

	// Transient members

	Scope::T <decltype (m_response_queue)> m_response_scope;
};

