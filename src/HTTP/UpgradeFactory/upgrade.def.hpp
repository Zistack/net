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
		if (this -> m_upgrade_methods . contains (protocol))
		{
			return this -> m_upgrade_methods . at (protocol) (request);
		}
	}

	return std::nullopt;
}
