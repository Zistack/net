template <typename RequestType>
struct T : Failure::Cancellable::T
{
	T (std::chrono::milliseconds output_timeout);

	void
	prime ();

	void
	run (IO::Interface::NonblockingOutputStream::T & nonblocking_output_stream);

	void
	cancel () override;

	void
	push (const RequestType & request);

	~T () = default;

	private:
	std::chrono::milliseconds output_timeout;

	Thread::ConcurrentQueue::T<std::reference_wrapper<const RequestType>>
	    request_queue;
};
