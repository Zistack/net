T::T (const Config::Value::T & config) : input_timeout (config.getInputTimeout ()), output_timeout (config.getOutputTimeout ()), close_timeout (config.getCloseTimeout ()), chunk_size (config.getChunkSize ()), temp_file_threshhold (config.getTempFileThreshhold ())
{
}
