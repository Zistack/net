template <typename Interface, typename Request, typename Response>
struct T
:	private InputInterface::T <Interface, Response>,
	private OutputInterface::T <Interface, Response>
{
	void
	prime ();

	template <typename InputStream, typename OutputStream>
	void
	run (InputStream && input_stream, OutputStream && output_stream);

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

	// Given members

	std::chrono::nanoseconds m_round_trip_timeout;

	// Internal members

	std::mutex m_queue_mutex;
};
