template
<
	typename UpgradeTarget,
	typename ... RequestArguments,
	typename ... ProtocolArguments
>
std::variant <std::unique_ptr <UpgradeTarget>, Response::T>
T::upgrade
(
	const std::tuple <RequestArguments ...> & request_arguments,
	const std::tuple <ProtocolArguments ...> & protocol_arguments
)
{
	using ProtocolData = typename UpgradeTarget::ProtocolData;

	std::pair <Request::T, ProtocolData> request_package =
		std::apply (UpgradeTarget::createRequest, request_arguments);

	Request::T & request = request_package . first;
	ProtocolData & protocol_data = request_package . second;

	Response::T response = this -> makeRequest (std::move (request));

	if (response . statusCode () == 101)
	{
		this -> cancel ();

		return std::apply
		(
			[&] (ProtocolArguments & ... protocol_arguments)
			{
				return std::make_unique <UpgradeTarget>
				(
					protocol_data,
					response,
					std::forward <ProtocolArguments> (protocol_arguments) ...
				);
			},
			protocol_arguments
		);
	}
	else
	{
		return response;
	}
}
