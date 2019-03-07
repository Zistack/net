static const std::string HOSTNAME = "Hostname";
static const std::string HOSTNAME_DESCRIPTION = "The hostname of the service.";

static const std::string PORT = "Port";
static const std::string PORT_DESCRIPTION =
    "Port or name of registered protocol being used.";

using T = GetConfig::Section::T<
    GetConfig::Member::
        T<GetConfig::String::T, true, HOSTNAME, HOSTNAME_DESCRIPTION>,
    GetConfig::Member::T<GetConfig::String::T, true, PORT, PORT_DESCRIPTION>>;
