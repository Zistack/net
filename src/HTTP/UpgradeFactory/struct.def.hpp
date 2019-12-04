template <typename ... UpgradeTargets>
struct T
{
	using ResponseAndProtocol = std::variant
	<
		std::pair <Response::T, std::unique_ptr <UpgradeTargets>> ...
	>;

	template <typename ... ResponseArguments, typename ... ProtocolArguments>
	T
	(
		const std::pair <ResponseArguments, ProtocolArguments> & ...
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

	std::map
	<
		Header::Upgrade::Protocol::T,
		ResponseAndProtocol (const Request::T & request)
	>
	m_upgrade_methods;
};
