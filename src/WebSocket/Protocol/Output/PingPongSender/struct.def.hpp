struct T
{
	T
	(
		std::chrono::milliseconds output_timeout,
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
	ping (const std::vector <uint8_t> & payload);

	void
	pong (const std::vector <uint8_t> & payload);

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

	// Given members

	std::chrono::milliseconds output_timeout;

	Thread::SleepMutex::T & output_mutex;

	// Internal members

	Thread::ConcurrentQueue::T <std::pair <Type::T, std::vector <uint8_t>>>
	output_queue;

	// Transient members

	Scope::T <decltype (output_queue)> output_scope;
};

static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
