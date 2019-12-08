template <typename Interface>
std::pair <HTTP::Request::T, typename T <Interface>::ProtocolData>
T <Interface>::createRequest (const URI::T & uri)
{
	assert (uri . authority);

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
			uri,
			"HTTP/1.1",
			std::initializer_list <std::pair <std::string, std::string>>
			{
				{"Host", uri . authority -> toString ()},
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
