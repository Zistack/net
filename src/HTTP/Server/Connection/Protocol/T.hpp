T::T (const Config::Value::T & config, Responder::T & responder) :
    FIFOProtocol::Server::Connection::Protocol::T<Request::T, Response::T> (
        config.getFIFOProtocolConfig ()),
    transfer_encoding_config (config.getTransferEncodingConfig ()),
    temp_file_threshhold (config.getTempFileThreshhold ()),
    responder (responder)
{
}
