T::T (IO::Interface::Protocol::T * protocol,
    std::chrono::milliseconds timeout) :
    protocol (protocol),
    timeout (timeout),
    spurious_read (false)
{
}