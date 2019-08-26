template <typename Protocol, typename Response, typename Details>
struct T : private Shared::T <Protocol, Details>
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

	~T () = default;

protected:

	const T &
	input () const;

	T &
	input ();

private:

	template <typename InputStream>
	void
	event (InputStream && input_stream);

	// Internal members

	Failure::ExceptionStore::T m_exception_store;
	ShutdownSignal::T m_input_shutdown_signal;

	Thread::ConcurrentQueue::T <Thread::Delay::T <Response>> m_response_queue;

	// Transient members

	SuppressingScope::T <ShutdownSignal::T> m_input_shutdown_scope;
	Scope::T <decltype (m_response_queue)> m_response_scope;
};

static_assert
(
	Failure::
		TypeTraits::
		IsCancellable::
		T
		<
			T
			<
				Interface::T
				<
					std::monostate,
					std::monostate,
					TypeTraits::ClientDetails::T
					<
						std::monostate,
						std::monostate
					>
				>,
				std::monostate,
				TypeTraits::ClientDetails::T <std::monostate, std::monostate>
			>
		>::
		value
);
