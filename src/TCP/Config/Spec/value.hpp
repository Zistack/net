const GetConfig::Section::Spec::T T::value = {
    {"Hostname",
        "The hostname of the service.",
        true,
        GetConfig::String::Type::T ()},
    {"Port",
        "Port or name of registered protocol being used.",
        true,
        GetConfig::String::Type::T ()}};
