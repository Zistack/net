template <typename Interface, typename Request, typename Response>
struct T
:	private InputInterface::T <Interface, Response>,
	private OutputInterface::T <Interface, Response>
{
	T (std::chrono::nanoseconds round_trip_timeout);

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

	~T () = default;

private:

	// Given members

	std::chrono::nanoseconds m_round_trip_timeout;

	// Internal members

	std::mutex m_queue_mutex;
};

static_assert
(
	IO::TypeTraits::IsProtocol::T
	<
		T
		<
			TypeTraits::Interface::T <std::monostate, std::monostate>,
			std::monostate,
			std::monostate
		>
	>::value
);
