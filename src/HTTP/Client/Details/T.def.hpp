
T::T
(
	std::chrono::milliseconds input_timeout,
	std::chrono::milliseconds output_timeout,
	TransferEncoding::Config::T transfer_encoding_config,
	uint64_t temp_file_threshhold
)
:	m_input_timeout (input_timeout),
	m_output_timeout (output_timeout),
	m_transfer_encoding_config (transfer_encoding_config),
	m_temp_file_threshhold (temp_file_threshhold)
{
}
