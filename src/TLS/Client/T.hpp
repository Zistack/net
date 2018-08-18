T::T (IO::Interface::Protocol::T & protocol,
    Context::T & context,
    uint64_t timeout_ns) :
    protocol (protocol),
    context (context),
    timeout_ns (timeout_ns),
    ssl (NULL),
    adapter (NULL)
{
}
