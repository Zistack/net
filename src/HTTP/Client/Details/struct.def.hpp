struct T
{
	T
	(
		std::chrono::nanoseconds input_timeout,
		std::chrono::nanoseconds output_timeout,
		TransferEncoding::Config::T transfer_encoding_config,
		uint64_t temp_file_threshhold
	);

	template <typename OutputStream>
	void
	writeRequest
	(
		const Request::T & request,
		OutputStream && output_stream
	) const;

	template <typename InputStream>
	Response::T
	readResponse (InputStream && input_stream) const;

	~T () = default;

private:

	std::chrono::nanoseconds m_input_timeout;
	std::chrono::nanoseconds m_output_timeout;
	TransferEncoding::Config::T m_transfer_encoding_config;
	uint64_t m_temp_file_threshhold;
};
