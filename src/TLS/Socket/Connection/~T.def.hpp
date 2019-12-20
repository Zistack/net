template <typename Credentials>
T <Credentials>::~T ()
{
	IO::CancelSignal::T cancel_signal;

	try
	{
		{
			Thread::Timer::T close_timer
			(
				this -> m_handshake_timeout,
				[&] () { cancel_signal . cancel (); }
			);
			this -> close (cancel_signal);
		}
		cancel_signal . clear ();
	}
	catch (Failure::CancelException::T)
	{
		throw Failure::ResourceError::T ("TLS close timed out\n");
	}

	gnutls_deinit (this -> session);
	close (this -> tcp_socket);
}
