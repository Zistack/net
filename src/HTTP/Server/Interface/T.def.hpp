T::T
(
	std::chrono::milliseconds input_timeout,
	std::chrono::milliseconds output_timeout,
	const TransferEncoding::Config::T & transfer_encoding_config,
	uint64_t temp_file_threshhold,
	Responder::T & responder
)
:	input_timeout (input_timeout),
	output_timeout (output_timeout),
	transfer_encoding_config (transfer_encoding_config),
	temp_file_threshhold (temp_file_threshhold),
	responder (responder)
{
}