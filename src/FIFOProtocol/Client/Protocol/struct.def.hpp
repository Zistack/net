template <typename Request, typename Response, typename Interface>
struct T
{
	template <typename ... Arguments>
	T
	(
		std::chrono::milliseconds round_trip_timeout,
		Arguments && ... arguments
	);

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

	std::chrono::milliseconds round_trip_timeout;

	// Internal members

	Interface interface;

	std::mutex queue_mutex;

	Input::T <Response, Interface> input;
	Output::T <Request, Interface> output;
};

static_assert
(
	IO::
		TypeTraits::
		IsProtocol::
		T
		<
			T
			<
				std::monostate,
				std::monostate,
				TypeTraits::ClientInterface::T <std::monostate, std::monostate>
			>
		>::
		value
);
