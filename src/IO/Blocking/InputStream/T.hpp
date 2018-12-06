T::T (Interface::NonblockingInputStream::T & input_stream,
    Interface::Watchable::T & cancel_signal) :
    input_stream (input_stream),
    cancel_signal (cancel_signal),
    start (0),
    end (0)
{
}
