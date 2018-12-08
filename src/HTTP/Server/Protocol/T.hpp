T::T (std::chrono::milliseconds input_timeout,
    std::chrono::milliseconds output_timeout) :
    FIFOProtocol::Server::Protocol::T<Request::T, Response::T> (input_timeout,
        output_timeout);
{
}
