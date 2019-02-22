const GetConfig::Section::Spec::T T::value = {
    {T::INPUT_TIMEOUT,
        "Timeout in milliseconds for reading a request from a client\n",
        false,
        GetConfig::UInt::Type::T (),
        1000},
    {T::OUTPUT_TIMEOUT,
        "Timeout in milliseconds for writing a response to a client\n",
        false,
        GetConfig::UInt::Type::T (),
        1000}};
