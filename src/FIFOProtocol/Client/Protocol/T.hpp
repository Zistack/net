template <class RequestType, class ResponseType>
T<RequestType, ResponseType>::T (const Config::T & config) :
    config (config),
    status_bit (status_mutex)
{
}
