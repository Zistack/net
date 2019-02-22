template <typename RequestType, typename ResponseType>
struct T : Failure::Cancellable::T
{
	T (std::chrono::milliseconds output_timeout);

	void
	prime ();

	void
	run (Protocol::T<RequestType, ResponseType> & protocol,
	    IO::Interface::NonblockingOutputStream::T & nonblocking_output_stream);

	void
	cancel () override;

	void
	push (const ::Protocol::Delay::T<ResponseType> & response_delay);

	~T () = default;

	private:
	std::chrono::milliseconds output_timeout;

	Thread::ConcurrentQueue::T<::Protocol::Delay::T<ResponseType>>
	    response_queue;

	Scope::T<decltype (response_queue)> response_scope;
};
