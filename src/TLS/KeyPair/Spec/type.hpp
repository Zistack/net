static const std::string CERTIFICATE_FILENAME = "Certificate-File";
static const std::string CERTIFICATE_FILENAME_DESCRIPTION =
    "Path to certificate file";

static const std::string PRIVATE_KEY_FILENAME = "Private-Key-File";
static const std::string PRIVATE_KEY_FILENAME_DESCRIPTION =
    "Path to private key file";

using T = GetConfig::Section::T<GetConfig::Member::T<GetConfig::String::T,
                                    false,
                                    CERTIFICATE_FILENAME,
                                    CERTIFICATE_FILENAME_DESCRIPTION>,
    GetConfig::Member::T<GetConfig::String::T,
        false,
        PRIVATE_KEY_FILENAME,
        PRIVATE_KEY_FILENAME_DESCRIPTION>>;
