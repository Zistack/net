struct T : Failure::Cancellable::T
{
	T (Thread::SleepMutex::T & output_mutex,
	    std::chrono::milliseconds output_timeout,
	    uint64_t chunk_size);

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
	sendFrame (const FrameHeader::T & frame_header,
	    Message::T & message,
	    IO::Interface::OutputStream::T & ouput_stream,
	    IO::CancelSignal::T & output_timeout_signal);

	Thread::SleepMutex::T & output_mutex;

	Thread::ConcurrentQueue::T<std::unique_ptr<Message::T>> output_queue;

	std::chrono::milliseconds output_timeout;
	uint64_t chunk_size;
};
