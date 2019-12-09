template <typename ... UpgradeTargets>
std::optional <typename T <UpgradeTargets ...>::ResponseAndProtocol>
T <UpgradeTargets ...>::upgrade
(
	const Header::Upgrade::T & upgrade,
	const Request::T & request
)
{
	for (auto && protocol : upgrade . protocols)
	{
		std::string protocol_string = protocol . toString ();

		auto upgrade_method_it =
			this -> m_upgrade_methods . find (protocol_string);

		if (upgrade_method_it != this -> m_upgrade_methods . end ())
		{
			return upgrade_method_it -> second (request);
		}
		else if (protocol . version)
		{
			upgrade_method_it =
				this -> m_upgrade_methods . find (protocol . name);

			if (upgrade_method_it != this -> m_upgrade_methods . end ())
			{
				return upgrade_method_it -> second (request);
			}
		}
	}

	return std::nullopt;
}
