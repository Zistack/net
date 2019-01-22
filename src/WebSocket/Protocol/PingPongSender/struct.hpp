struct T : Failure::Cancellable::T
{
	T (Thread::SleepMutex::T & output_mutex,
	    std::chrono::milliseconds output_timeout);

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
	sendFrame (const FrameHeader::T & frame_header,
	    IO::Interface::InputStream::T & input_stream,
	    IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_timeout_signal);

	Thread::SleepMutex::T & output_mutex;

	Thread::ConcurrentQueue::T<std::pair<Type::T, std::vector<uint8_t>>>
	    output_queue;

	std::chrono::milliseconds output_timeout;
};
