static const std::string TCP_CONFIG = "Connection";
static const std::string TCP_CONFIG_DESCRIPTION =
    "Configuration for the underlying TCP connection.";

static const std::string CA_PATH = "CA-Path";
static const std::string CA_PATH_DESCRIPTION =
    "Path to directory containing trusted root certificates.";

static const std::string SERVER_NAME = "Server-Name";
static const std::string SERVER_NAME_DESCRIPTION =
    "Name that this service identifies as.";

static const std::string IDENTITY = "Identity";
static const std::string IDENTITY_DESCRIPTION =
    "The keypair that the client uses for client authentication.";

using T = GetConfig::Section::T<
    GetConfig::Member::
        T<TCP::Config::T, false, TCP_CONFIG, TCP_CONFIG_DESCRIPTION>,
    GetConfig::Member::
        T<GetConfig::String::T, false, CA_PATH, CA_PATH_DESCRIPTION>,
    GetConfig::Member::
        T<GetConfig::String::T, false, SERVER_NAME, SERVER_NAME_DESCRIPTION>,
    GetConfig::Member::T<KeyPair::T, true, IDENTITY, IDENTITY_DESCRIPTION>>;
