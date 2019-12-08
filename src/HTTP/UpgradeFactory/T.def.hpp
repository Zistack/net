template <typename ... UpgradeTargets>
template <typename ... ResponseArguments, typename ... ProtocolArguments>
T <UpgradeTargets ...>::T
(
	const std::pair <ResponseArguments, ProtocolArguments> & ...
		upgrade_arguments
)
{
	(
		this -> m_upgrade_methods . emplace
		(
			UpgradeTargets::NAME . toString (),
			[
				response_arguments = upgrade_arguments . first,
				protocol_arguments = upgrade_arguments . second
			]
			(
				const Request::T & request
			)
			{
				using ProtocolData = typename UpgradeTargets::ProtocolData;

				std::pair <Response::T, ProtocolData> response_package =
					std::apply
					(
						[&] (ResponseArguments & ... response_arguments)
						{
							return UpgradeTargets::createResponse
							(
								request,
								std::forward <ResponseArguments>
								(
									response_arguments
								) ...
							);
						},
						response_arguments
					);

				Response::T & response = response_package . first;
				ProtocolData & protocol_data = response_package . second;

				std::unique_ptr <UpgradeTargets> protocol = std::apply
				(
					[&] (ProtocolArguments & ... protocol_arguments)
					{
						return std::make_unique <UpgradeTargets>
						(
							request,
							protocol_data,
							std::forward <ProtocolArguments>
							(
								protocol_arguments
							) ...
						);
					},
					protocol_arguments
				);

				return std::make_pair (std::move (response), protocol);
			}
		), ...
	);
}
