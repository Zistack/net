struct T
{
	T
	(
		std::chrono::milliseconds output_timeout,
		uint64_t chunk_size,
		Thread::SleepMutex::T & output_mutex
	);

	void
	prime ();

	template <typename OutputStream>
	void
	run (OutputStream && output_stream);

	void
	cancel ();

	void
	send (Message::T && message);

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

	// Given members

	std::chrono::milliseconds output_timeout;

	uint64_t chunk_size;

	Thread::SleepMutex::T & output_mutex;

	// Internal members

	Thread::ConcurrentQueue::T <Message::T> output_queue;

	// Transient members

	Scope::T <decltype (output_queue)> output_scope;
};

static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
