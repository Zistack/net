template <typename RequestType, typename ResponseType>
T<RequestType, ResponseType>::T (const Config::Value::T & config) :
    input (config.getInputTimeout ()),
    output (config.getOutputTimeout ())
{
}
