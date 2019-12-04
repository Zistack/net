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
	using UpgradeFactory = typename UpgradeTarget::UpgradeFactory;

	UpgradeFactory upgrade_factory;

	Response::T response = this -> makeRequest
	(
		std::apply
		(
			[&] (RequestArguments ... request_arguments)
			{
				upgrade_factory . createUpgradeRequest
				(
					std::forward <RequestArguments> (request_arguments) ...
				);
			},
			request_arguments
		)
	);

	if (response . statusCode () == 101)
	{
		this -> cancel ();

		return std::apply
		(
			[]
			(
				const UpgradeFactory & upgrade_factory,
				const Request::T & request,
				ProtocolArguments ... protocol_arguments
			)
			{
				return std::make_unique <UpgradeTarget>
				(
					upgrade_factory,
					request,
					std::forward <ProtocolArguments> (protocol_arguments) ...
				);
			},
			std::tuple_cat
			(
				std::forward_as_tuple (upgrade_factory, response),
				protocol_arguments
			)
		);
	}
	else
	{
		return response;
	}
}
