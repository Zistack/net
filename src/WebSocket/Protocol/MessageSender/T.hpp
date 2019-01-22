T::T (Thread::SleepMutex::T & output_mutex,
    std::chrono::milliseconds output_timeout,
    uint64_t chunk_size) :
    output_mutex (output_mutex),
    output_timeout (output_timeout),
    chunk_size (chunk_size)
{
}
