template
<
	typename UpgradeTarget,
	typename ... RequestArguments,
	typename ... ClientProtocolArguments
>
std::unique_ptr <typename UpgradeTarget::ClientProtocol>
T::upgrade
(
	const std::tuple <RequestArguments ...> & request_arguments,
	const std::tuple <ClientProtocolArguments ...> & client_protocol_arguments
)
{
	Response::T response = this -> makeRequest
	(
		std::apply (UpgradeTarget::createUpgradeRequest, request_arguments)
	);

	if (response . statusCode () == 101)
	{
		this -> cancel ();

		return std::apply
		(
			UpgradeTarget::createClientProtocol,
			std::tuple_cat
			(
				std::forward_as_tuple (response),
				client_protocol_arguments
			)
		);
	}
	else
	{
		// IDK what to do with the response.

		return nullptr;
	}
}
