template <typename Interface, bool upgrade_required>
struct T : WebSocket::Protocol::T <Interface>
{
	using ResponseFactory = ResponseFactory::T <upgrade_required>;

	T
	(
		const HTTP::Request::T & request,
		const ResponseFactory & response,
		const Config::T & config
	);

	~T () = default;

	static const HTTP::Header::Upgrade::Protocol::T NAME;
};
