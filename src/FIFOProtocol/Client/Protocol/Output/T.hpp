template <typename RequestType, typename ResponseType>
T<RequestType, ResponseType>::T (std::chrono::milliseconds output_timeout) :
    output_timeout (output_timeout)
{
}
