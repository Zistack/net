template <typename Request, typename Response, typename Details>
struct T
:	private Input::T
	<
		Interface::T <Request, Response, Details>,
		Response,
		Details
	>,
	private Output::T
	<
		Interface::T <Request, Response, Details>,
		Request,
		Details
	>
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

protected:

	// Internal members

	Details m_details;

private:

	// Given members

	std::chrono::milliseconds m_round_trip_timeout;

	// Internal members

	std::mutex m_queue_mutex;
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
				TypeTraits::ClientDetails::T <std::monostate, std::monostate>
			>
		>::
		value
);
