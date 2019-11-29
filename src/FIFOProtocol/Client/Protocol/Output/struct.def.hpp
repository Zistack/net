template <typename Interface, typename Request>
struct T
{
protected:

	T () = default;

	void
	prime ();

	template <typename OutputStream>
	void
	run (OutputStream && output_stream);

	void
	cancel ();

	void
	push (const Request & request);

	void
	push (Request && request);

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

	Thread::ConcurrentQueue::T <Request> m_request_queue;

	// Transient members

	Scope::T <decltype (m_request_queue)> m_request_scope;
};

