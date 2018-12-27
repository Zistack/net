T::T (const Config::T & config, Responder::T & responder) :
    FIFOProtocol::Server::Connection::Protocol::T<Request::T, Response::T> (
        config.server_config),
    transfer_encoding_config (config.transfer_encoding_config),
    responder (responder)
{
}
