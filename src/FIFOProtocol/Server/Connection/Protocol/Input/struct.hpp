template <typename Request, typename Response, typename Interface>
struct T
{
	T (Interface & interface, Output::T<Response, Interface> & output);

	void
	prime ();

	template <typename InputStream>
	void
	run (InputStream && input_stream);

	void
	cancel ();

	~T () = default;

	private:
	template <typename InputStream>
	void
	event (InputStream && input_stream, Thread::Nursery::T & nursery);

	void
	respond (const Request & request,
	    Thread::Delay::T<Response> response_delay);

	// Given members

	Interface & interface;
	Output::T<Response, Interface> & output;

	// Internal members

	Failure::ExceptionStore::T exception_store;
	Shutdown::Signal::T input_shutdown_signal;

	// Transient members

	SuppressingScope::T<Shutdown::Signal::T> input_shutdown_scope;

	static_assert (Failure::TypeTraits::IsCancellable::T<T>::value);
};
