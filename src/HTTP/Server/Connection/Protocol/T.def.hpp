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
:	Base::T <Responder, UpgradeTargets ...>
	(
		input_timeout,
		output_timeout,
		transfer_encoding_config,
		temp_file_threshhold,
		responder_arguments,
		upgrade_arguments ...
	),
	m_cancelled (false)
{
}
