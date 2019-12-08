template <typename Interface>
struct T : WebSocket::Protocol::T <Interface>
{
	using ProtocolData = ProtocolData::T;

	T
	(
		const ProtocolData & protocol_data,
		const HTTP::Response::T & response,
		const Config::T & config
	);

	~T () = default;

	static std::pair <HTTP::Request::T, ProtocolData>
	createRequest (const URI::T & uri);
};
