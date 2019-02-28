struct T : IO::Interface::Protocol::T
{
	T (const Config::Value::T & config);

	void
	prime () override;

	void
	run (IO::Interface::NonblockingInputStream::T & input_stream,
	    IO::Interface::NonblockingOutputStream::T & output_stream) override;

	void
	cancel () override;

	void
	send (std::unique_ptr<Message::T> && message);

	void
	ping (const std::vector<uint8_t> & payload);

	void
	pong (const std::vector<uint8_t> & payload);

	~T () override = default;

	private:
	// Input helpers

	void
	input (Shutdown::Signal::T & input_shutdown_signal);

	void
	processFrames (IO::Blocking::InputStream::T & input_stream,
	    Shutdown::Signal::T & input_shutdown_signal,
	    IO::CancelSignal::T & input_timeout_signal);

	void
	processEvent (IO::Blocking::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_timeout_signal);

	void
	waitForCloseFrame (IO::Blocking::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_timeout_signal);

	void
	waitEvent (IO::Blocking::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_timeout_signal);

	void
	loadCloseBuffer (FrameHeader::T & close_header,
	    IO::Blocking::InputStream::T & input_stream);

	// Output helpers

	void
	output (Failure::CancelScope::T & output_cancel_scope);

	void
	sendCloseFrame (IO::Blocking::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_timeout_signal);

	void
	unloadCloseBuffer (FrameHeader::T & close_header,
	    IO::Blocking::OutputStream::T & output_stream);

	// Utility helper

	std::unique_ptr<HTTP::Entity::T>
	pickEntity (bool final_frame, uint64_t payload_length);

	// Given members

	std::chrono::milliseconds input_timeout;
	std::chrono::milliseconds output_timeout;
	std::chrono::milliseconds close_timeout;

	uint64_t chunk_size;
	uint64_t temp_file_threshhold;

	// Internal members

	Failure::ExceptionStore::T exception_store;

	// This shouldn't be a thing.  I don't like moving nurseries around like 
	// this.  That said, it technically works?
	std::mutex nursery_mutex;
	std::unique_ptr<Thread::Nursery::T> nursery;

	// Input state

	std::unique_ptr<Message::T> message;

	// Output state

	Thread::SleepMutex::T output_mutex;
	MessageSender::T message_sender;
	PingPongSender::T ping_pong_sender;

	std::mutex close_mutex;
	uint16_t status_code;
	std::optional<IO::Vector::T> reason;

	// Interface

	Dispatcher::T & dispatcher;
};
