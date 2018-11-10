template <class RequestType, class ResponseType>
T<RequestType, ResponseType>::T (std::chrono::milliseconds input_timeout,
    std::chrono::milliseconds output_timeout,
    std::chrono::milliseconds round_trip_timeout) :
    input_timeout (input_timeout),
    output_timeout (output_timeout),
    round_trip_timeout (round_trip_timeout),
    status_bit (sleep_lock)
{
}
