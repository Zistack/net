template <typename Interface, bool upgrade_required>
struct T : WebSocket::Protocol::T <Interface>
{
	using ProtocolData = ProtocolData::T;

	T
	(
		const HTTP::Request::T & request,
		const ProtocolData & protocol_data,
		const Config::T & config
	);

	~T () = default;

	static std::pair <HTTP::Response::T, ProtocolData>
	createResponse (const HTTP::Request::T & request);

	static const HTTP::Header::Upgrade::Protocol::T NAME;
};
