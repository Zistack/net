struct T : Failure::Cancellable::T
{
	T (std::chrono::milliseconds output_timeout,
	    Thread::SleepMutex::T & output_mutex);

	void
	prime ();

	void
	run (IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_timeout_signal);

	void
	cancel () override;

	void
	ping (const std::vector<uint8_t> & payload);

	void
	pong (const std::vector<uint8_t> & payload);

	~T () = default;

	private:
	void
	writeFrame (const FrameHeader::T & frame_header,
	    const std::vector<uint8_t> & payload,
	    IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_timeout_signal);

	// Given members

	std::chrono::milliseconds output_timeout;

	Thread::SleepMutex::T & output_mutex;

	// Internal members

	Thread::ConcurrentQueue::T<std::pair<Type::T, std::vector<uint8_t>>>
	    output_queue;

	// Transient members

	Scope::T<decltype (output_queue)> output_scope;
};
