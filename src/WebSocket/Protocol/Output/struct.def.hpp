struct T
{
	T (std::chrono::milliseconds output_timeout, uint64_t chunk_size);

	void
	prime ();

	template <typename OutputStream>
	void
	run (OutputStream && output_stream);

	void
	cancel ();

	void
	cancel (const CloseMessage::T & close_message);

	void
	send (Message::T && message);

	void
	ping (const std::vector <uint8_t> & payload);

	void
	pong (const std::vector <uint8_t> & payload);

	~T () = default;

private:

	template <typename OutputStream>
	void
	close (OutputStream && output_stream);

	// Given members

	std::chrono::milliseconds output_timeout;

	// Internal members

	Thread::SleepMutex::T output_mutex;
	MessageSender::T message_sender;
	PingPongSender::T ping_pong_sender;

	std::mutex close_mutex;
	StatusBit::T <std::mutex> close_bit;

	CloseMessage::T close_message;

	// Transient members

	Scope::T <decltype (close_bit)> close_scope;
};

static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
