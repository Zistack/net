template <typename Specialization>
struct T
{
	template <typename CancelSignal>
	void
	handshake (CancelSignal && cancel_signal);

	// Given members

	const int tcp_socket;

	// Internal members

	const gnutls_session_t session;

protected:

	template
	<
		typename ... SpecializationArguments,
		typename = std::enable_if_t
		<
			std::is_constructible_v
			<
				Specialization,
				gnutls_session_t,
				SpecializationArguments ...
			>
		>
	>
	T
	(
		int tcp_socket,
		unsigned int flags,
		std::chrono::nanoseconds handshake_timeout,
		SpecializationArguments && ... specialization_arguments
	);

	T (const T & other) = delete;

	T (T && other) = delete;

	T &
	operator = (const T & other) = delete;

	T &
	operator = (T && other) = delete;

	~T ();

private:

	template <typename CancelSignal>
	void
	close (CancelSignal && cancel_signal);

	// Given members

	std::chrono::nanoseconds m_handshake_timeout;

	// Internal members

	Specialization m_specialization;
};
