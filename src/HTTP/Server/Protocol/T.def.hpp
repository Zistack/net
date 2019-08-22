template
<
	typename Responder,
	typename ... ResponderArguments,
	typename ... UpgradeSpecs
>
T <Responder, std::tuple <ResponderArguments ...>, UpgradeSpecs ...>::T
(
	const Config::T & config,
	const std::tuple <ResponderArguments ...> & responder_arguments,
	const typename UpgradeSpecs::Arguments & ... upgrade_arguments
)
:	m_config (config),
	m_responder_arguments (responder_arguments),
	m_upgrade_arguments (upgrade_arguments ...)
{
}
