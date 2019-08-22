template <typename Responder, typename ... UpgradeTargets>
template <typename ... ResponderArguments, typename ... UpgradeArguments>
T <Responder, UpgradeTargets ...>::T
(
	std::chrono::milliseconds input_timeout,
	std::chrono::milliseconds output_timeout,
	const TransferEncoding::Config::T & transfer_encoding_config,
	uint64_t temp_file_threshhold,
	const std::tuple <ResponderArguments ...> & responder_arguments,
	UpgradeArguments && ... upgrade_arguments
)
:	m_input_timeout (input_timeout),
	m_output_timeout (output_timeout),
	m_transfer_encoding_config (transfer_encoding_config),
	m_temp_file_threshhold (temp_file_threshhold),
	m_responder (std::make_from_tuple <Responder> (responder_arguments)),
	m_upgrade_factory (std::forward <UpgradeArguments> (upgrade_arguments) ...)
{
}
