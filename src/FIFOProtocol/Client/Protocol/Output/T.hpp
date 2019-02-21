template <typename RequestType>
T<RequestType>::T (std::chrono::milliseconds output_timeout) :
    output_timeout (output_timeout)
{
}
