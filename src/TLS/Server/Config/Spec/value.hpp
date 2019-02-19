const GetConfig::Section::Spec::T value = {
    {T::TCP_CONFIG,
        "Configuration for the underlying TCP server.",
        false,
        TCP::Config::Type::T ()},
    {T::CA_PATH,
        "Path to directory containing trusted root certificates.",
        true,
        GetConfig::String::Type::T ()},
    {T::IDENTITY,
        "The keypair that the server uses for authentication.",
        false,
        KeyPair::Type::T ()},
    {T::CONNECTION_CONFIG,
        "The settings for the bridge between the TLS protocol and the protocol "
        "on top.",
        false,
        TLS::Connection::Config::Type::T (),
        TLS::Connection::Config::Value::T ()}};
