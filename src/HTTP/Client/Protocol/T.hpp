T::T (const Config::T & config) :
    FIFOProtocol::Client::Protocol::T<Request::T, Response::T> (
        config.client_config),
    transfer_encoding_config (config.transfer_encoding_config)
{
}
