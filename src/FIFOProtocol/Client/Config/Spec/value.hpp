const GetConfig::Section::Spec::T T::value = {
    {T::INPUT_TIMEOUT,
        "Timeout in milliseconds for reading a response from the server.",
        false,
        GetConfig::UInt::Type::T (),
        1000},
    {T::OUTPUT_TIMEOUT,
        "Timeout in milliseconds for writing a request to the server.",
        false,
        GetConfig::UInt::Type::T (),
        1000},
    {T::ROUND_TRIP_TIMEOUT,
        "Timeout in milliseconds for sending a request to the server and "
        "recieving a response.",
        false,
        GetConfig::UInt::Type::T (),
        2000}};
