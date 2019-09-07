template
<
	typename UpgradeTarget,
	typename ... RequestArguments,
	typename ... ClientProtocolArguments
>
std::variant <std::unique_ptr <UpgradeTarget>, Response::T>
T::upgrade
(
	const std::tuple <RequestArguments ...> & request_arguments,
	const std::tuple <ClientProtocolArguments ...> & client_protocol_arguments
)
{
	typename UpgradeTarget::ClientUpgradeFactory upgrade_factory;

	Response::T response = this -> makeRequest
	(
		std::apply
		(
			UpgradeTarget::ClientUpgradeFactory::createUpgradeRequest,
			std::tuple_cat
			(
				std::forward_as_tuple (& upgrade_factory),
				request_arguments
			)
		)
	);

	if (response . statusCode () == 101)
	{
		this -> cancel ();

		return std::apply
		(
			UpgradeTarget::ClientUpgradeFactory::createClientProtocol,
			std::tuple_cat
			(
				std::forward_as_tuple (& upgrade_factory, response),
				client_protocol_arguments
			)
		);
	}
	else
	{
		return response;
	}
}
