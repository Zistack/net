template <typename Output>
struct T : private Shared::T <Output>
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
	ping (const std::vector <uint8_t> & payload);

	void
	pong (const std::vector <uint8_t> & payload);

	~T () = default;

protected:

	const T &
	pingPongSender () const;

	T &
	pingPongSender ();

private:

	template <typename OutputStream>
	void
	writeFrame
	(
		const FrameHeader::T & frame_header,
		const std::vector <uint8_t> & payload,
		OutputStream && output_stream
	);

	// Internal members

	Thread::ConcurrentQueue::T <std::pair <Type::T, std::vector <uint8_t>>>
		m_output_queue;

	// Transient members

	Scope::T <decltype (m_output_queue)> m_output_scope;
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
					Protocol::Interface::T <TypeTraits::Dispatcher::T>
				>
			>
		>::
		value
);
