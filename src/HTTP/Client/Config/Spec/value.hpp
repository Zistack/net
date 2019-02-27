const GetConfig::Section::Spec::T T::value = {
    {T::FIFO_PROTOCOL_CONFIG,
        "Timeout values for HTTP client.",
        false,
        FIFOProtocol::Client::Config::Type::T (),
        FIFOProtocol::Client::Config::Value::T ()},
    {T::TRANSFER_ENCODING_CONFIG,
        "Transfer encoding configuration to use when sending requests to the "
        "server.",
        false,
        TransferEncoding::Encoder::Config::Type::T (),
        TransferEncoding::Encoder::Config::Value::T ()},
    {T::TEMP_FILE_THRESHHOLD,
        "When the size of the response is known, response entities larger than "
        "this number of bytes will be read into a temporary file rather than a "
        "buffer on the heap.",
        false,
        GetConfig::UInt::Type::T (),
        4096}};
