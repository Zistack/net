template <typename Interface>
std::pair <HTTP::Request::T, typename T <Interface>::ProtocolData>
T <Interface>::createRequest
(
	const HTTP::Header::Host::T & host,
	const URI::T & resource
)
{
	HandshakeKey::T client_key;
	Crypto::Util::getRandom (client_key . data (), client_key . size ());

	ProtocolData protocol_data;

	Crypto::Base64::encode
	(
		client_key,
		client_key . size (),
		protocol_data . client_key_base64
	);

	return std::make_pair
	(
		HTTP::Request::T
		(
			"GET",
			resource,
			"HTTP/1.1",
			host,
			{
				{"Upgrade", "WebSocket"},
				{"Connection", "Upgrade"},
				{"Sec-Websocket-Key", protocol_data . client_key_base64},
				{"Sec-WebSocket-Version", "13"}
			},
			std::nullopt
		),
		protocol_data
	);
}
