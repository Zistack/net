template <class RequestType, class ResponseType>
struct T : IO::Interface::Protocol::T
{
	T (std::chrono::milliseconds input_timeout,
	    std::chrono::milliseconds output_timeout);

	void
	run (IO::Interface::NonblockingInputStream::T * input_stream,
	    IO::Interface::NonblockingOutputStream::T * output_stream) override;

	void
	stop () override;

	virtual ~T () override = default;

	protected:
	virtual RequestType
	readRequest (IO::Interface::InputStream::T * input_stream) = 0;

	virtual ResponseType
	map (RequestType request) = 0;

	virtual void
	writeResponse (ResponseType response,
	    IO::Interface::OutputStream::T * output_stream) = 0;

	virtual void
	destroyRequest (RequestType request) = 0;

	virtual void
	destroyResponse (ResponseType response) = 0;

	private:
	void
	output (IO::Blocking::OutputStream::T & output_stream);

	void
	event (IO::Blocking::InputStream::T & input_stream,
	    Thread::Nursery::T & nursery);

	void
	computeResponse (RequestType request,
	    ::Protocol::Delay::T<ResponseType> delay);

	Shutdown::Signal::T shutdown_signal;

	std::chrono::milliseconds input_timeout;
	IO::Signal::T input_timeout_signal;

	std::chrono::milliseconds output_timeout;
	IO::Signal::T output_timeout_signal;

	::Protocol::DelayQueue::T<ResponseType> response_queue;
};
