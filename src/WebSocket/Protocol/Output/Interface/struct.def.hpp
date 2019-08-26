template <typename Protocol>
struct T : Implementation::T <Protocol>
{
	using Implementation::T <Protocol>::T;

private:

	using Implementation::T <Protocol>::m_output_timeout;
	using Implementation::T <Protocol>::m_output_mutex;

	friend MessageSender::T <T>;
	friend PingPongSender::T <T>;
};
