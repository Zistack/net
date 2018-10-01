template <class RequestType, class ResponseType>
struct T : IO::Interface::Protocol::T
{
	T (std::chrono::milliseconds input_timeout,
	    std::chrono::milliseconds output_timeout,
	    std::chrono::milliseconds round_trip_timeout);

	void
	run (IO::Interface::NonblockingInputStream::T * input_stream,
	    IO::Interface::NonblockingOutputStream::T * output_stream) override;

	void
	stop () override;

	ResponseType
	makeRequest (RequestType request);

	virtual ~T () override = default;

	protected:
	virtual void
	writeRequest (RequestType request,
	    IO::Interface::OutputStream::T * output_stream) = 0;

	virtual ResponseType
	readResponse (IO::Interface::InputStream::T * input_stream) = 0;

	private:
	void
	event (IO::Blocking::InputStream::T & input_stream);

	Status::Bit::T status_bit;
	Shutdown::Signal::T shutdown_signal;

	IO::Blocking::OutputStream::T * output_stream;

	std::chrono::milliseconds input_timeout;
	IO::Signal::T input_timeout_signal;

	std::chrono::milliseconds output_timeout;
	IO::Signal::T output_timeout_signal;

	std::chrono::milliseconds round_trip_timeout;

	Protocol::DelayQueue::T<ResponseType> response_queue;
};
