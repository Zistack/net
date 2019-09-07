struct T : Base::T
{
	T (const Config::T & config);

	template
	<
		typename UpgradeTarget,
		typename ... RequestArguments,
		typename ... ClientProtocolArguments
	>
	std::variant <std::unique_ptr <UpgradeTarget>, Response::T>
	upgrade
	(
		const std::tuple <RequestArguments ...> & request_arguments,
		const std::tuple <ClientProtocolArguments ...> &
			client_protocol_arguments
	);
};
