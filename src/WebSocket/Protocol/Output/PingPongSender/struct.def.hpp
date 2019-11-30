template <typename Interface>
struct T
{
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

protected:

	T () = default;

	const T &
	pingPongSender () const;

	T &
	pingPongSender ();

	~T () = default;

private:

	template <typename OutputStream>
	void
	writeFrame
	(
		const FrameHeader::T & frame_header,
		const std::vector <uint8_t> & payload,
		OutputStream && output_stream
	);

	// Access to external members

	const Interface &
	interface () const;

	Interface &
	interface ();

	// Internal members

	Thread::ConcurrentQueue::T <std::pair <Type::T, std::vector <uint8_t>>>
		m_output_queue;

	// Transient members

	Scope::T <decltype (m_output_queue)> m_output_scope;
};
