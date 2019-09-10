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
		std::string protocol_string = protocol . toString ();

		if (this -> m_upgrade_methods . contains (protocol_string))
		{
			return this -> m_upgrade_methods . at (protocol_string) (request);
		}
		else if (protocol . version)
		{
			if (this -> m_upgrade_methods . contains (protocol . name))
			{
				return this ->
					m_upgrade_methods .
					at (protocol . name) (request);
			}
		}
	}

	return std::nullopt;
}
