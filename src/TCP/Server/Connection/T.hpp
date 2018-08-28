T::T (IO::Interface::Protocol::T & protocol,
    IO::Signal::T & signal,
    IO::Socket::T * socket,
    IO::Interface::OutputStream::T * log) :
    protocol (protocol),
    signal (signal),
    socket (socket),
    log (log)
{
}
