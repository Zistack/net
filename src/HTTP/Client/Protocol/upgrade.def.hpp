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
	using RequestFactory = typename UpgradeTarget::RequestFactory;

	RequestFactory request_factory =
		std::make_from_tuple <RequestFactory> (request_arguments);

	Response::T response = this -> makeRequest (request_factory . request);

	if (response . statusCode () == 101)
	{
		this -> cancel ();

		return std::apply
		(
			[]
			(
				const RequestFactory & request_factory,
				const Response::T & response,
				ProtocolArguments ... protocol_arguments
			)
			{
				return std::make_unique <UpgradeTarget>
				(
					request_factory,
					response,
					std::forward <ProtocolArguments> (protocol_arguments) ...
				);
			},
			std::tuple_cat
			(
				std::forward_as_tuple (request_factory, response),
				protocol_arguments
			)
		);
	}
	else
	{
		return response;
	}
}
