const GetConfig::Section::Spec::T T::value = {
    {T::FIFO_PROTOCOL_CONFIG,
        "Timeout values for HTTP server.",
        false,
        FIFOProtocol::Server::Config::Type::T (),
        FIFOProtocol::Server::Config::Value::T ()},
    {T::TRANSFER_ENCODING_CONFIG,
        "Transfer encoding configuration to use when sending responses to "
        "clients.",
        false,
        TransferEncoding::Encoder::Config::Type::T (),
        TransferEncoding::Encoder::Config::Value::T ()},
    {T::TEMP_FILE_THRESHHOLD,
        "When the size of a request is known, request entities larger than "
        "this number of bytes will be read into a temporary file rather than a "
        "buffer on the heap.",
        false,
        GetConfig::UInt::Type::T (),
        4096}};
