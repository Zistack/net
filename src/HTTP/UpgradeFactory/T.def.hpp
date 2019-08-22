template <typename ... UpgradeTargets>
template <typename ... UpgradeArguments>
T <UpgradeTargets ...>::T (UpgradeArguments && ... upgrade_arguments)
{
	(
		this -> m_upgrade_methods . emplace
		(
			UpgradeTargets::PROTOCOL,
			[& upgrade_arguments] (const Request::T & request)
			{
				return std::apply
				(
					UpgradeTargets::createServerProtocol,
					std::tuple_cat
					(
						std::forward_as_tuple (request),
						std::forward <UpgradeArguments> (upgrade_arguments)
					)
				);
			}
		), ...
	);
}
