template <typename Interface, typename Request, typename Response>
struct T : InputOutputInterface::T <Interface, Request, Response>
{
	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

	void
	stop ();

	void
	cancel ();

	Response
	makeRequest (const Request & request);

	Response
	makeRequest (Request && request);

protected:

	T (std::chrono::nanoseconds round_trip_timeout);

	const T &
	fifoProtocol () const;

	T &
	fifoProtocol ();

	~T () = default;

private:

	using InputInterface::T <Interface, Response>::readResponse;
	using InputInterface::T <Interface, Response>::readActive;
	using InputInterface::T <Interface, Response>::readIdle;
	using InputInterface::T <Interface, Response>::queueActive;
	using InputInterface::T <Interface, Response>::queueIdle;

	using InputOutputInterface::T <Interface, Request, Response>::writeRequest;
	using InputOutputInterface::T <Interface, Request, Response>::pushInput;
	using InputOutputInterface::T <Interface, Request, Response>::stopInput;
	using InputOutputInterface::T <Interface, Request, Response>::writeActive;
	using InputOutputInterface::T <Interface, Request, Response>::writeIdle;

	// Given members

	std::chrono::nanoseconds m_round_trip_timeout;
};
