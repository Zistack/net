const GetConfig::Section::Spec::T T::value = {
    {T::TIMEOUT,
        "Maximum number of milliseconds that a transfer of TLS data (usually a "
        "whole record) is allowed to take.",
        false,
        GetConfig::UInt::Type::T (),
        2000},
    {T::BUFFER_SIZE,
        "Buffer size used for moving data between TLS and nested protocol.",
        false,
        GetConfig::UInt::Type::T (),
        4096}};
