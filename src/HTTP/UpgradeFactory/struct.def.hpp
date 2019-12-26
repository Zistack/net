template <typename ... UpgradeTargets>
struct T
{
	using ResponseAndProtocol = std::variant
	<
		std::pair <Response::T, std::unique_ptr <UpgradeTargets>> ...
	>;

	template
	<
		typename ... ResponseArgumentPacks,
		typename ... ProtocolArgumentPacks
	>
	T
	(
		const std::pair <ResponseArgumentPacks, ProtocolArgumentPacks> & ...
			upgrade_arguments
	);

	std::optional <ResponseAndProtocol>
	upgrade
	(
		const Header::Upgrade::T & upgrade,
		const Request::T & request
	);

	~T () = default;

private:

	template
	<
		typename UpgradeTarget,
		typename ... ResponseArguments,
		typename ... ProtocolArguments
	>
	static ResponseAndProtocol
	make
	(
		const std::tuple <ResponseArguments ...> & response_arguments,
		const std::tuple <ProtocolArguments ...> & protocol_arguments,
		const Request::T & request
	);

	std::map
	<
		Header::Upgrade::Protocol::T,
		std::function <ResponseAndProtocol (const Request::T & request)>
	>
	m_upgrade_methods;
};
