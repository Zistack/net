template
<
	typename Protocol,
	typename Request,
	typename Response,
	typename Details
>
struct T
{
	T () = default;

	void
	prime ();

	template <typename InputStream>
	void
	run (InputStream && input_stream);

	void
	cancel ();

	~T () = default;

protected:

	const T &
	input () const;

	T &
	input ();

private:

	template <typename InputStream>
	void
	event (InputStream && input_stream, Thread::Nursery::T & nursery);

	void
	respond
	(
		const Request & request,
		Thread::Delay::T <Response> response_delay
	);

	// External members

	const Output::T <Protocol, Response, Details> &
	output () const;

	Output::T <Protocol, Response, Details> &
	output ();

	const Details &
	details () const;

	Details &
	details ();

	// Internal members

	Failure::ExceptionStore::T m_exception_store;
	ShutdownSignal::T m_input_shutdown_signal;

	// Transient members

	SuppressingScope::T <ShutdownSignal::T> m_input_shutdown_scope;
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
					TypeTraits::ServerDetails::T
					<
						std::monostate,
						std::monostate
					>
				>,
				std::monostate,
				std::monostate,
				TypeTraits::ServerDetails::T <std::monostate, std::monostate>
			>
		>::
		value
);
