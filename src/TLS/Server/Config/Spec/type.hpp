static const std::string TCP_CONFIG = "Connection";
static const std::string TCP_CONFIG_DESCRIPTION =
    "Configuration for the underlying TCP server.";

static const std::string CA_PATH = "CA-Path";
static const std::string CA_PATH_DESCRIPTION =
    "Path to directory containing trusted root certificates.";

static const std::string IDENTITY = "Identity";
static const std::string IDENTITY_DESCRIPTION =
    "The keypair that the server uses for authentication.";

using T = GetConfig::Section::T<
    GetConfig::Member::
        T<TCP::Config::T, false, TCP_CONFIG, TCP_CONFIG_DESCRIPTION>,
    GetConfig::Member::
        T<GetConfig::String::T, true, CA_PATH, CA_PATH_DESCRIPTION>,
    GetConfig::Member::T<KeyPair::T, false, IDENTITY, IDENTITY_DESCRIPTION>>;
