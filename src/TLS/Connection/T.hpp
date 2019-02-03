T::T (IO::Interface::Protocol::T & protocol,
    std::chrono::milliseconds timeout) :
    protocol (protocol),
    timeout (timeout),
    buffer_size (1024),
    spurious_read (false)
{
}
