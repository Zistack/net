const GetConfig::Section::Spec::T T::value = {
    {T::CERTIFICATE_FILENAME,
        "Path to certificate file",
        false,
        GetConfig::String::Type::T ()},
    {T::PRIVATE_KEY_FILENAME,
        "Path to private key file",
        false,
        GetConfig::String::Type::T ()}};
