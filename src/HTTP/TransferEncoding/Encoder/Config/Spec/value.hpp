const GetConfig::Section::Spec::T T::value = {
    {T::TRANSFER_ENCODING,
        "The transfer encoding to apply when sending messages.  Uses the same "
        "format as the corresponding header in the HTTP specification.",
        true,
        GetConfig::String::Type::T ()},
    {T::CHUNK_SIZE,
        "The chunk size in bytes to use when using the chunked transfer "
        "encoding.",
        false,
        GetConfig::UInt::Type::T (),
        4096}};
