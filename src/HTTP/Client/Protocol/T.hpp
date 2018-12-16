T::T (std::chrono::milliseconds io_timeout,
    std::chrono::milliseconds round_trip_timeout) :
    FIFOProtocol::Client::Protocol::T<Request::T, Response::T> (io_timeout,
        io_timeout,
        round_trip_timeout)
{
}
