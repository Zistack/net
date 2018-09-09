T::T (IO::Interface::Protocol::T * protocol,
    IO::Socket::T * socket,
    IO::Interface::OutputStream::T * log) :
    protocol (protocol),
    socket (socket),
    log (log)
{
	this->signal = new IO::Signal::T ();
}
