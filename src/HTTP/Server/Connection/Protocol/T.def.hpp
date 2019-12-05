template <typename Interface, typename ... UpgradeTargets>
template <typename ... UpgradeArguments>
T <Interface, UpgradeTargets ...>::T
(
	const Config::T & config,
	UpgradeArguments && ... upgrade_arguments
)
:	FIFOProtocolInterface::T <Interface, UpgradeTargets ...>
	(
		config . inputTimeout (),
		config . outputTimeout (),
		config . transferEncodingConfig (),
		config . tempFileThreshhold (),
		upgrade_arguments ...
	),
	m_cancelled (false)
{
}
