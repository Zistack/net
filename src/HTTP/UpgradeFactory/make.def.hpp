template <typename ... UpgradeTargets>
template
<
	typename UpgradeTarget,
	typename ... ResponseArguments,
	typename ... ProtocolArguments
>
typename T <UpgradeTargets ...>::ResponseAndProtocol
T <UpgradeTargets ...>::make
(
	const std::tuple <ResponseArguments ...> & response_arguments,
	const std::tuple <ProtocolArguments ...> & protocol_arguments,
	const Request::T & request
)
{
	using ProtocolData = typename UpgradeTarget::ProtocolData;

	std::pair <Response::T, ProtocolData> response_package =
		std::apply
		(
			[&] (ResponseArguments ... response_arguments)
			{
				return UpgradeTarget::createResponse
				(
					request,
					std::forward <ResponseArguments> (response_arguments) ...
				);
			},
			response_arguments
		);

	Response::T & response = response_package . first;
	ProtocolData & protocol_data = response_package . second;

	std::unique_ptr <UpgradeTarget> protocol = std::apply
	(
		[&] (ProtocolArguments ... protocol_arguments)
		{
			return std::make_unique <UpgradeTarget>
			(
				request,
				protocol_data,
				std::forward <ProtocolArguments> (protocol_arguments) ...
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
