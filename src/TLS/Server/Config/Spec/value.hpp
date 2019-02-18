const GetConfig::Section::Spec::T value = {
    {T::TCP_CONFIG,
        "Configuration for the underlying TCP server",
        false,
        TCP::Config::Type::T ()},
    {T::CA_PATH,
        "Path to directory containing trusted root certificates",
        true,
        GetConfig::String::Type::T ()},
    {T::IDENTITY,
        "The keypair that the server uses for authentication",
        false,
        KeyPair::Type::T ()}};
