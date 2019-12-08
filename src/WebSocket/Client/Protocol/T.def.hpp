template <typename Interface>
T <Interface>::T
(
	const ProtocolData & protocol_data,
	const HTTP::Response::T & response,
	const Config::T & config
)
:	WebSocket::Protocol::T <Interface> (config)
{
	const HTTP::HeaderMap::T & headers = response . headers ();

	HTTP::Util::validateClientUpgradeCondition
	(
		headers . contains ("Upgrade") &&
			(headers . at ("Upgrade") == HTTP::Util::normalize ("WebSocket")),
		"Expected 'Upgrade' header with value 'WebSocket'\n"
	);

	HTTP::Util::validateClientUpgradeCondition
	(
		headers . contains ("Connection") &&
			(headers . at ("Connection") == HTTP::Util::normalize ("Upgrade")),
		"Expected 'Connection' header with value 'Upgrade'\n"
	);

	std::string expected_server_key_hash_base64 =
		Util::computeServerKeyFromClientKey
		(
			protocol_data . client_key_base64
		);

	HTTP::Util::validateClientUpgradeCondition
	(
		headers . contains ("Sec-WebSocket-Accept") &&
			(
				headers . at ("Sec-WebSocket-Accept") ==
				expected_server_key_hash_base64
			),
		"Expected 'Sec-WebSocket-Accept' header with value '" +
			expected_server_key_hash_base64 +
			"'\n"
	);
}
