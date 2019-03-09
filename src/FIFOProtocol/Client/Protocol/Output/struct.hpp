template <typename Request, typename Interface>
struct T : Failure::Cancellable::T
{
	T (Interface & interface);

	void
	prime ();

	template <typename OutputStream>
	void
	run (OutputStream && output_stream);

	void
	cancel () override;

	void
	push (const Request & request);

	void
	push (Request && request);

	~T () = default;

	private:
	// Given members

	Interface & interface;

	// Internal members

	Thread::ConcurrentQueue::T<Request> request_queue;

	// Transient members

	Scope::T<decltype (request_queue)> request_scope;
};
