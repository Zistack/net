template <typename Interface, typename ... UpgradeTargets>
template <typename ... UpgradeArguments>
T <Interface, UpgradeTargets ...>::T
(
	std::chrono::nanoseconds input_timeout,
	std::chrono::nanoseconds output_timeout,
	const TransferEncoding::Config::T & transfer_encoding_config,
	uint64_t temp_file_threshhold,
	UpgradeArguments && ... upgrade_arguments
)
:	m_input_timeout (input_timeout),
	m_output_timeout (output_timeout),
	m_transfer_encoding_config (transfer_encoding_config),
	m_temp_file_threshhold (temp_file_threshhold),
	m_upgrade_factory (std::forward <UpgradeArguments> (upgrade_arguments) ...)
{
}
