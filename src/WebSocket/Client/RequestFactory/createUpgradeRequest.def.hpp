HTTP::Request::T
T::createUpgradeRequest (const URI::T & uri)
{
	assert (uri . authority);

	HandshakeKey::T client_key;
	Crypto::Util::getRandom (client_key . data (), client_key . size ());

	Crypto::Base64::encode
	(
		client_key,
		client_key . size (),
		this -> client_key_base64
	);

	return HTTP::Request::T
	(
		"GET",
		uri,
		"HTTP/1.1",
		std::initializer_list <std::pair <std::string, std::string>>
		{
			{"Host", uri . authority -> toString ()},
			{"Upgrade", "WebSocket"},
			{"Connection", "Upgrade"},
			{"Sec-Websocket-Key", this -> client_key_base64},
			{"Sec-WebSocket-Version", "13"}
		},
		std::nullopt
	);
}
