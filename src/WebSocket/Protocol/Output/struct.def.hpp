struct T : private SenderInterface::T
{
	void
	prime ();

	template <typename OutputStream>
	void
	run (OutputStream && output_stream);

	void
	cancel ();

	void
	cancel (const CloseMessage::T & close_message);

	using SenderInterface::T::send;

	using SenderInterface::T::ping;
	using SenderInterface::T::pong;

protected:

	T (std::chrono::nanoseconds output_timeout, uint64_t chunk_size);

	const T &
	output () const;

	T &
	output ();

	~T () = default;

private:

	template <typename OutputStream>
	void
	close (OutputStream && output_stream);

	// Internal members

	std::mutex m_close_mutex;
	StatusBit::T <std::mutex> m_close_bit;

	CloseMessage::T m_close_message;

	// Transient members

	Scope::T <decltype (m_close_bit)> m_close_scope;
};
