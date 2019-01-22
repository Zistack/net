T::T (Thread::SleepMutex::T & output_mutex,
    std::chrono::milliseconds output_timeout) :
    output_mutex (output_mutex),
    output_timeout (output_timeout)
{
}
