struct T : Base::T
{
	T (const Config::T & config);

	template
	<
		typename UpgradeTarget,
		typename ... RequestArguments,
		typename ... ClientProtocolArguments
	>
	std::unique_ptr <typename UpgradeTarget::ClientProtocol>
	upgrade
	(
		const std::tuple <RequestArguments ...> & request_arguments,
		const std::tuple <ClientProtocolArguments ...> &
			client_protocol_arguments
	);
};
