struct T : private FIFOProtocolInterface::T
{
	T (const Config::T & config);

	using FIFOProtocolInterface::T::prime;
	using FIFOProtocolInterface::T::run;
	using FIFOProtocolInterface::T::cancel;
	using FIFOProtocolInterface::T::makeRequest;

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

	~T () = default;
};
