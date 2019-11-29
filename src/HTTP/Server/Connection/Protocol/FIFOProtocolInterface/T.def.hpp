template <typename Interface, typename ... UpgradeTargets>
template <typename ... UpgradeArguments>
T <Interface, UpgradeTargets ...>::T
(
	const Config::T & config,
	UpgradeArguments && ... upgrade_arguments
)
:	m_input_timeout (config . inputTimeout ()),
	m_output_timeout (config . outputTimeout ()),
	m_transfer_encoding_config (config . transferEncodingConfig ()),
	m_temp_file_threshhold (config . tempFileThreshhold ()),
	m_upgrade_factory (std::forward <UpgradeArguments> (upgrade_arguments) ...)
{
}
