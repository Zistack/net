template <class RequestType, class ResponseType>
struct T : Interface::Protocol::T
{
	T (uint64_t intput_timeout,
	    uint64_t output_timeout,
	    uint64_t round_trip_timeout);

	void
	init (Interface::NonblockingInputStream::T * input_stream,
	    Interface::NonblockingOutputStream::T * output_stream) override;

	void
	event () override;

	void
	clean () override;

	~T () = default;

	ResponseType
	makeRequest (RequestType request);

	void
	cleanQueue ();

	void
	lock ();

	void
	unlock ();

	virtual void
	writeRequest (RequestType request,
	    Interface::OutputStream::T * output_stream) = 0;

	virtual ResponseType
	readResponse (Interface::InputStream::T * input_stream) = 0;

	std::mutex mutex;
	std::condition_variable condition_variable;
	bool locked;
	bool active;

	uint64_t input_timeout;
	Signal::T * input_timeout_signal;
	Blocking::InputStream::T * input_stream;

	uint64_t output_timeout;
	Signal::T * output_timeout_signal;
	Blocking::OutputStream::T * output_stream;

	uint64_t round_trip_timeout;

	Thread::ConcurrentQueue::T<std::promise<ResponseType> *> response_queue;
};
