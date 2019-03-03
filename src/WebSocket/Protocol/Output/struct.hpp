struct T : Failure::Cancellable::T
{
	T (std::chrono::milliseconds output_timeout, uint64_t chunk_size);

	void
	prime ();

	void
	run (IO::Interface::NonblockingOutputStream::T & nonblocking_output_stream);

	void
	cancel () override;

	void
	cancel (const CloseMessage::T & close_message);

	void
	send (std::unique_ptr<Message::T> && message);

	void
	ping (const std::vector<uint8_t> & payload);

	void
	pong (const std::vector<uint8_t> & payload);

	~T () = default;

	private:
	void
	close (IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_timeout_signal);

	// Given members

	std::chrono::milliseconds output_timeout;

	// Internal members

	Thread::SleepMutex::T output_mutex;
	MessageSender::T message_sender;
	PingPongSender::T ping_pong_sender;

	std::mutex close_mutex;
	Status::Bit::T<std::mutex> close_bit;

	CloseMessage::T close_message;

	// Transient members

	Scope::T<Status::Bit::T<std::mutex>> close_scope;
};
