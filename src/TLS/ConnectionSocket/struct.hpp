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
	T (std::pair<int, struct tls *> p);

	Thread::SleepMutex::T socket_mutex;
	bool spurious_read;

	private:
	Input::T
	input () const;

	Output::T
	output () const;
};
