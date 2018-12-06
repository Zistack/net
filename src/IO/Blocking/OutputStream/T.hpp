T::T (Interface::NonblockingOutputStream::T & output_stream,
    Interface::Watchable::T & cancel_signal) :
    output_stream (output_stream),
    cancel_signal (cancel_signal)
{
}
