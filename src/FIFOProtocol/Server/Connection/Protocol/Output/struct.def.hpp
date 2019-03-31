template <typename Response, typename Interface>
struct T
{
	T (Interface & interface);

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

	private:
	// Given members

	Interface & interface;

	// Internal members

	Thread::ConcurrentQueue::T <Thread::Delay::T <Response>> response_queue;

	// Transient members

	Scope::T <decltype (response_queue)> response_scope;

	static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
};
