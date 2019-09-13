template <typename Protocol>
struct T
:	private MessageSender::T <Interface::T <Protocol>>,
	private PingPongSender::T <Interface::T <Protocol>>
{
	T (std::chrono::nanoseconds output_timeout, uint64_t chunk_size);

	void
	prime ();

	template <typename OutputStream>
	void
	run (OutputStream && output_stream);

	void
	cancel ();

	void
	cancel (const CloseMessage::T & close_message);

	using MessageSender::T <Interface::T <Protocol>>::send;

	using PingPongSender::T <Interface::T <Protocol>>::ping;
	using PingPongSender::T <Interface::T <Protocol>>::pong;

	~T () = default;

protected:

	const T &
	output () const;

	T &
	output ();

	// Given members shared with submodules

	std::chrono::nanoseconds m_output_timeout;

	// Internal members shared with submodules

	std::mutex m_rng_mutex;
	Crypto::RNG::T m_rng;

	std::mutex m_output_mutex;

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

	// Friends

	friend MessageSender::T <Interface::T <Protocol>>;
	friend PingPongSender::T <Interface::T <Protocol>>;
};

static_assert
(
	Failure::
		TypeTraits::
		IsCancellable::
		T <T <Interface::T <TypeTraits::Dispatcher::T>>>::
		value
);
