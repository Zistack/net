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
	push (const RequestType & request);

	~T () = default;

	private:
	std::chrono::milliseconds output_timeout;

	Thread::ConcurrentQueue::T<std::reference_wrapper<const RequestType>>
	    request_queue;

	Scope::T<decltype (request_queue)> request_scope;
};
