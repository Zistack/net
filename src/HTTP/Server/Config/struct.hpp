struct T
{
	T () = default;

	T (JSON::Value::T * config_value);

	~T () = default;

	FIFOProtocol::Server::Config::T server_config;
	TransferEncoding::Encoder::Config::T transfer_encoding_config;
};
