T::T (const Config::Value::T & config, Dispatcher::T & dispatcher) :
    input (config.getInputTimeout (),
        config.getCloseTimeout (),
        config.getTempFileThreshhold (),
        this->output,
        dispatcher,
        *this),
    output (config.getOutputTimeout (), config.getChunkSize ())
{
}
