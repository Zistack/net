template <class... CancelSignals>
T::T (Interface::NonblockingOutputStream::T & output_stream,
    CancelSignals &... cancel_signals) :
    output_stream (output_stream),
    cancel_signals{cancel_signals...}
{
}

T::T (Interface::NonblockingOutputStream::T & output_stream,
    std::initializer_list<std::reference_wrapper<Interface::Watchable::T>>
        cancel_signals) :
    output_stream (output_stream),
    cancel_signals (cancel_signals)
{
}
