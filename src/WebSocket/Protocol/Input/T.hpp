T::T (std::chrono::milliseconds input_timeout,
    std::chrono::milliseconds close_timeout,
    uint64_t temp_file_threshhold,
    Output::T & output,
    Dispatcher::T & dispatcher,
    Protocol::T & protocol) :
    input_timeout (input_timeout),
    close_timeout (close_timeout),
    temp_file_threshhold (temp_file_threshhold),
    output (output),
    dispatcher (dispatcher),
    protocol (protocol)
{
}
