template <typename Protocol, typename Response, typename Details>
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

	~T () = default;

protected:

	const T &
	output () const;

	T &
	output ();

private:

	// External members

	const Details &
	details () const;

	Details &
	details ();

	// Internal members

	Thread::ConcurrentQueue::T <Thread::Delay::T <Response>> m_response_queue;

	// Transient members

	Scope::T <decltype (m_response_queue)> m_response_scope;
};

