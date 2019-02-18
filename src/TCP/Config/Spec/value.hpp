const GetConfig::Section::Spec::T T::value = {
    {T::HOSTNAME,
        "The hostname of the service.",
        true,
        GetConfig::String::Type::T ()},
    {T::PORT,
        "Port or name of registered protocol being used.",
        true,
        GetConfig::String::Type::T ()}};
