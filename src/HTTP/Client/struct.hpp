struct T : IO::Interface::Protocol::T
{
	T () = default;

	void
	init (IO::Socket::T * socket) override;

	void
	event () override;

	void
	clean () override;

	~T () = default;

	IO::Socket::T * socket;

	ConcurrentQueue <ResponsePromise::T *> response_queue;

	std::mutex mutex;
};
