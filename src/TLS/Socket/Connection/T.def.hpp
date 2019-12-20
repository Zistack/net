template <typename Specialization>
template <typename ... SpecializationArguments, typename>
T <Specialization>::T
(
	int tcp_socket,
	unsigned int flags,
	std::chrono::nanoseconds handshake_timeout,
	SpecializationArguments && ... specialization_arguments
)
:	tcp_socket (tcp_socket),
	session (Util::session (flags)),
	m_handshake_timeout (handshake_timeout),
	m_specialization
	(
		this -> session,
		std::forward <SpecializationArguments> (specialization_arguments) ...
	)
{
	gnutls_set_transport_int (this -> session, this -> tcp_socket);

	IO::CancelSignal::T cancel_signal;

	try
	{
		{
			Thread::Timer::T handshake_timer
			(
				this -> m_handshake_timeout,
				[&] () { cancel_signal . cancel (); }
			);
			this -> handshake (cancel_signal);
		}
		cancel_signal . clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("TLS handshake timed out\n");
	}
}
