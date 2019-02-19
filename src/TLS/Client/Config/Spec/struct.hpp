struct T
{
	static constexpr const char * const TCP_CONFIG = "Connection";
	static constexpr const char * const CA_PATH = "CA-Path";
	static constexpr const char * const SERVER_NAME = "Server-Name";
	static constexpr const char * const IDENTITY = "Identity";
	static constexpr const char * const CONNECTION_CONFIG = "Protocol-Limits";

	static const GetConfig::Section::Spec::T value;
};
