std::string
computeServerKeyFromClientKey (const std::string & client_key_base64)
{
	std::string server_key_source =
		client_key_base64 + "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";

	Server::HandshakeKey::T server_key;

	Crypto::Util::sha1
	(
		(const uint8_t *) server_key_source . data (),
		(uint32_t) server_key_source . size (),
		server_key . data ()
	);

	std::string server_key_base64
	(
		Crypto::Base64::encodedLength (server_key . size ()),
		'\0'
	);

	Crypto::Base64::encode
	(
		server_key,
		server_key . size (),
		server_key_base64
	);

	return server_key_base64;
}
