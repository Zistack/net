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
	send (Message::T && message);

protected:

	T (uint64_t chunk_size);

	const T &
	messageSender () const;

	T &
	messageSender ();

	~T () = default;

private:

	template <typename OutputStream>
	void
	writeMessage (Message::T & message, OutputStream && output_stream);

	template <typename OutputStream>
	void
	writeFrame
	(
		const FrameHeader::T & frame_header,
		Message::T & message,
		uint64_t chunk_position,
		OutputStream && output_stream
	);

	// Access to external members

	const Interface &
	interface () const;

	Interface &
	interface ();

	// Given members

	uint64_t m_chunk_size;

	// Internal members

	Thread::ConcurrentQueue::T <Message::T> m_output_queue;

	// Transient members

	Scope::T <decltype (m_output_queue)> m_output_scope;
};
