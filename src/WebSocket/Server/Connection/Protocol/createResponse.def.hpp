template <typename Interface, bool upgrade_required>
std::pair
<
	HTTP::Response::T,
	typename T <Interface, upgrade_required>::ProtocolData
>
T <Interface, upgrade_required>::createResponse
(
	const HTTP::Request::T & request
)
{
	const HTTP::HeaderMap::T & headers = request . headers ();

	HTTP::Util::validateServerUpgradeCondition <upgrade_required>
	(
		request . method () == "GET",
		"Upgrading to the WebSocket protocol requires that the method be "
			"'GET'\n"
	);

	HTTP::Util::validateServerUpgradeCondition <upgrade_required>
	(
		headers . contains ("Connection") &&
			HTTP::Header::Connection::T (headers . at ("Connection")) .
				options .
				count (HTTP::Util::normalize ("Upgrade")),
		"Upgrading to the WebSocket protocol requires the 'Connection' header "
			"field to exist and contain the token 'Upgrade'\n"
	);

	HTTP::Util::validateServerUpgradeCondition <upgrade_required>
	(
		headers . at ("Sec-Websocket-Version") == "13",
		"Websocket Version " +
			headers . at ("Sec-WebSocket-Version") +
			" is unsupported\n",
		{{"Sec-WebSocket-Version", "13"}}
	);

	std::string client_key_base64;

	HTTP::Util::validateServerUpgradeCondition <upgrade_required>
	(
		headers . contains ("Sec-WebSocket-Key") &&
			Crypto::Base64::validate
			(
				(client_key_base64 = headers . at ("Sec-WebSocket-Key")),
				Crypto::Base64::encodedLength
				(
					std::tuple_size <Client::HandshakeKey::T>::value
				),
				Crypto::Base64::encodedLengthWithoutPadding
				(
					std::tuple_size <Client::HandshakeKey::T>::value
				)
			),
		"Upgrading to the WebSocket protocol requires that the "
			"'Sec-Websocket-Key' header field exists and is set to a 128-bit "
			"random number encoded as a base64 string\n"
	);

	std::string server_key_base64 =
		Util::computeServerKeyFromClientKey (client_key_base64);

	return std::make_pair
	(
		HTTP::Response::T
		(
			"HTTP/1.1",
			101,
			HTTP::Util::reasonPhrase (101),
			{
				{"Upgrade", "WebSocket"},
				{"Connection", "Upgrade"},
				{"Sec-WebSocket-Accept", server_key_base64}
			},
			std::nullopt
		),
		ProtocolData ()
	);
}
