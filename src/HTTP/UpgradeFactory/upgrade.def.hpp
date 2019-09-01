template <typename ... UpgradeTargets>
std::optional <typename T <UpgradeTargets ...>::ResponseAndProtocol>
T <UpgradeTargets ...>::upgrade
(
	const Header::Upgrade::T & upgrade,
	const Request::T & request
)
{
	for (auto && protocol : upgrade . m_protocols)
	{
		std::string normalized_protocol = normalize (protocol . m_name);

		if (this -> m_upgrade_methods . contains (normalized_protocol))
		{
			return this -> m_upgrade_methods . at (normalized_protocol) (request);
		}
	}

	return std::nullopt;
}
