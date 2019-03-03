struct T : Failure::Cancellable::T
{
	T (std::chrono::milliseconds output_timeout,
	    uint64_t chunk_size,
	    Thread::SleepMutex::T & output_mutex);

	void
	prime ();

	void
	run (IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_timeout_signal);

	void
	cancel () override;

	void
	send (std::unique_ptr<Message::T> && message);

	~T () = default;

	private:
	void
	writeMessage (Message::T & message,
	    IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_timeout_signal);

	void
	writeFrame (const FrameHeader::T & frame_header,
	    Message::T & message,
	    IO::Interface::OutputStream::T & ouput_stream,
	    IO::CancelSignal::T & output_timeout_signal);

	// Given members

	std::chrono::milliseconds output_timeout;

	uint64_t chunk_size;

	Thread::SleepMutex::T & output_mutex;

	// Internal members

	Thread::ConcurrentQueue::T<std::unique_ptr<Message::T>> output_queue;

	// Transient members

	Scope::T<decltype (output_queue)> output_scope;
};
