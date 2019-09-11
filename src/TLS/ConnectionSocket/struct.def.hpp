struct T : Socket::T
{
	T (int tcp_socket, struct tls * tls_context);

	template <typename CancelSignal>
	void
	handshake (CancelSignal && cancel_signal);

	Reciever::T
	reciever ();

	Sender::T
	sender ();

	template <typename CancelSignal>
	void
	close (CancelSignal && cancel_signal);

	virtual ~T () = default;

protected:

	T (std::pair <int, struct tls *> p);

	std::mutex m_socket_mutex;
	bool m_spurious_read;

private:

	IO::FileDescriptor::Input::T
	input () const;

	IO::FileDescriptor::Output::T
	output () const;
};
