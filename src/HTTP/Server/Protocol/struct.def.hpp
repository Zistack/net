template
<
	typename Responder,
	typename ... ResponderArguments,
	typename ... UpgradeSpecs
>
struct T <Responder, std::tuple <ResponderArguments ...>, UpgradeSpecs ...>
{
	T
	(
		const Config::T & config,
		const std::tuple <ResponderArguments ...> & responder_arguments,
		const typename UpgradeSpecs::Arguments & ... upgrade_arguments
	);

	std::unique_ptr
	<
		Connection::Protocol::T <Responder, typename UpgradeSpecs::Target ...>
	>
	make ();

	~T () = default;

private:

	Config::T m_config;
	std::tuple <ResponderArguments ...> m_responder_arguments;
	std::tuple <typename UpgradeSpecs::Arguments ...> m_upgrade_arguments;
};
