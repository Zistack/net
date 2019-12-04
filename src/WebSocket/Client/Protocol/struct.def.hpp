template <typename Interface>
struct T : WebSocket::Protocol::T <Interface>
{
	using UpgradeFactory = UpgradeFactory::T;

	T
	(
		const UpgradeFactory & upgrade_factory,
		const HTTP::Response::T & response,
		const Config::T & config
	);

	~T () = default;
};
