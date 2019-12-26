template <typename Interface, typename ... UpgradeTargets>
template <typename ... UpgradeArguments>
T <Interface, UpgradeTargets ...>::T
(
	const Config::T & config,
	const std::optional <HostData::T> & host_data,
	UpgradeArguments && ... upgrade_arguments
)
:	FIFOProtocolInterface::T <Interface, UpgradeTargets ...>
	(
		config . inputTimeout (),
		config . outputTimeout (),
		config . transferEncodingConfig (),
		config . tempFileThreshhold (),
		host_data,
		upgrade_arguments ...
	),
	m_cancelled (false)
{
}
