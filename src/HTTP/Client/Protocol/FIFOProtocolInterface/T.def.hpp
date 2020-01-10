template <typename Interface>
T <Interface>::T (
	std::chrono::nanoseconds input_timeout,
	std::chrono::nanoseconds output_timeout,
	std::chrono::nanoseconds round_trip_timeout,
	const TransferEncoding::Config::T & transfer_encoding_config,
	uint64_t temp_file_threshhold
)
:	FIFOProtocol::Client::Protocol::T <T, Request::T, Response::T>
	(
		round_trip_timeout
	),
	m_input_timeout (input_timeout),
	m_output_timeout (output_timeout),
	m_transfer_encoding_config (transfer_encoding_config),
	m_temp_file_threshhold (temp_file_threshhold)
{
}
