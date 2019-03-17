template <typename Response, typename Interface>
struct T
{
	T (Interface & interface);

	void
	prime ();

	template <typename InputStream>
	void
	run (InputStream && input_stream);

	void
	cancel ();

	void
	push (const Thread::Delay::T<Response> & response_delay);

	~T () = default;

	private:
	template <typename InputStream>
	void
	event (InputStream && input_stream);

	// Given members

	Interface & interface;

	// Internal members

	Failure::ExceptionStore::T exception_store;
	Shutdown::Signal::T input_shutdown_signal;

	Thread::ConcurrentQueue::T<Thread::Delay::T<Response>> response_queue;

	// Transient members

	SuppressingScope::T<Shutdown::Signal::T> input_shutdown_scope;
	Scope::T<decltype (response_queue)> response_scope;

	static_assert (Failure::TypeTraits::IsCancellable::T<T>::value);
};
