template <class RequestType, class ResponseType>
T<RequestType, ResponseType>::T (uint64_t input_timeout,
    uint64_t output_timeout) :
    input_timeout (input_timeout),
    output_timeout (output_timeout)
{
}
