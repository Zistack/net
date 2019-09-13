template <typename Protocol, typename Request, typename Details>
struct T : private Shared::T <Protocol, Details>
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
	push (const Request & request);

	void
	push (Request && request);

	~T () = default;

protected:

	const T &
	output () const;

	T &
	output ();

private:

	// Internal members

	Thread::ConcurrentQueue::T <Request> m_request_queue;

	// Transient members

	Scope::T <decltype (m_request_queue)> m_request_scope;
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
