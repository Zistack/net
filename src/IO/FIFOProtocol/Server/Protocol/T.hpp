template <class RequestType, class ResponseType>
T<RequestType, ResponseType>::T (std::chrono::milliseconds input_timeout,
    std::chrono::milliseconds output_timeout) :
    input_timeout (input_timeout),
    output_timeout (output_timeout)
{
}
