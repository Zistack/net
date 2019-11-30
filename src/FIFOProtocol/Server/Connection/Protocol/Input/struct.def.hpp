template <typename Interface, typename Request, typename Response>
struct T
{
	void
	prime ();

	template <typename InputStream>
	void
	run (InputStream && input_stream);

	void
	cancel ();

protected:

	T () = default;

	const T &
	input () const;

	T &
	input ();

	~T () = default;

private:

	template <typename InputStream>
	void
	event
	(
		InputStream && input_stream,
		Thread::Nursery::Collection::T <true> & nursery
	);

	void
	respond
	(
		const Request & request,
		Thread::Delay::T <Response> response_delay
	);

	// Access to external members

	const Interface &
	interface () const;

	Interface &
	interface ();

	// Internal members

	Failure::ExceptionStore::T m_exception_store;
	ShutdownSignal::T m_input_shutdown_signal;

	// Transient members

	SuppressingScope::T <ShutdownSignal::T> m_input_shutdown_scope;
};

