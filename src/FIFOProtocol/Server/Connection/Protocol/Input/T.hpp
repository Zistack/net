template <typename RequestType, typename ResponseType>
T<RequestType, ResponseType>::T (std::chrono::milliseconds input_timeout) :
    input_timeout (input_timeout)
{
}
