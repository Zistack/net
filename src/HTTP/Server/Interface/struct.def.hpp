struct T
{
	T
	(
		std::chrono::milliseconds input_timeout,
		std::chrono::milliseconds output_timeout,
		const TransferEncoding::Config::T & transfer_encoding_config,
		uint64_t temp_file_threshhold,
		Responder::T & responder
	);

	template <typename InputStream>
	Request::T
	readRequest (InputStream && input_stream) const;

	Response::T
	map (const Request::T & request);

	template <typename OutputStream>
	void
	writeResponse
	(
		const Response::T & response,
		OutputStream && output_stream
	) const;

	~T () = default;

private:

	std::chrono::milliseconds input_timeout;
	std::chrono::milliseconds output_timeout;
	const TransferEncoding::Config::T & transfer_encoding_config;
	uint64_t temp_file_threshhold;

	Responder::T & responder;
};
