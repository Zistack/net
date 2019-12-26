template <typename ... UpgradeTargets>
template
<
	typename ... ResponseArgumentPacks,
	typename ... ProtocolArgumentPacks
>
T <UpgradeTargets ...>::T
(
	const std::pair <ResponseArgumentPacks, ProtocolArgumentPacks> & ...
		upgrade_arguments
)
{
	(
		this -> m_upgrade_methods . emplace
		(
			UpgradeTargets::NAME,
			[
				response_arguments = upgrade_arguments . first,
				protocol_arguments = upgrade_arguments . second
			]
			(
				const Request::T & request
			)
			{
				return T::make <UpgradeTargets>
				(
					response_arguments,
					protocol_arguments,
					request
				);
			}
		), ...
	);
}
