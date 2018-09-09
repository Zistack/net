template <class RequestType, class ResponseType>
struct T : Interface::Protocol::T
{
	T (std::chrono::milliseconds input_timeout,
	    std::chrono::milliseconds output_timeout);

	void
	init (Interface::NonblockingInputStream::T * input_stream,
	    Interface::NonblockingOutputStream::T * output_stream,
	    Failure::ExceptionStore::T & exception_store,
	    std::function<void(void)> stop) override;

	void
	event () override;

	void
	clean () override;

	~T () = default;

	void
	run ();

	void
	computeResponse (RequestType request, std::promise<ResponseType> * promise);

	void
	cleanQueue ();

	virtual RequestType
	readRequest (Interface::InputStream::T * input_stream) = 0;

	virtual ResponseType
	map (RequestType request) = 0;

	virtual void
	writeResponse (ResponseType response,
	    IO::Interface::OutputStream::T * output_stream) = 0;

	virtual void
	destroyRequest (RequestType request) = 0;

	virtual void
	destroyResponse (ResponseType response) = 0;

	std::chrono::milliseconds input_timeout;
	Signal::T * input_timeout_signal;
	Blocking::InputStream::T * input_stream;

	std::chrono::milliseconds output_timeout;
	Signal::T * output_timeout_signal;
	Blocking::OutputStream::T * output_stream;

	std::function<void(void)> stop;

	Thread::Nursery::T * nursery;

	Thread::ConcurrentQueue::T<std::promise<ResponseType> *> response_queue;
};
