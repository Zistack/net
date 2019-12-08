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
						[&] (auto && ... response_arguments)
						{
							return UpgradeTargets::createResponse
							(
								request,
								std::forward <decltype (response_arguments)>
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
					[&] (auto && ... protocol_arguments)
					{
						return std::make_unique <UpgradeTargets>
						(
							request,
							protocol_data,
							std::forward <decltype (protocol_arguments)>
							(
								protocol_arguments
							) ...
						);
					},
					protocol_arguments
				);

				return std::make_pair
				(
					std::move (response),
					std::move (protocol)
				);
			}
		), ...
	);
}
