template <typename Interface, typename Request, typename Response>
struct T
{
	void
	prime ();

	template <typename OutputStream>
	void
	run (OutputStream && output_stream);

	void
	stop ();

	void
	cancel ();

	void
	push
	(
		const Request & request,
		const Thread::Delay::T <Response> & response_delay
	);

	void
	push
	(
		Request && request,
		const Thread::Delay::T <Response> & response_delay
	);

protected:

	T () = default;

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

	Thread::ConcurrentQueue::T
	<
		std::pair <Request, Thread::Delay::T <Response>>
	>
	m_request_queue;

	// Transient members

	Scope::T <decltype (m_request_queue)> m_request_scope;
};
