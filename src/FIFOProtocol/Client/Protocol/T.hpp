template <typename RequestType, typename ResponseType>
T<RequestType, ResponseType>::T (const Config::Value::T & config) :
    round_trip_timeout (config.getRoundTripTimeout ()),
    input (config.getInputTimeout ()),
    output (config.getOutputTimeout ())
{
}
