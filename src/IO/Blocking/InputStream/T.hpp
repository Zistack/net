template <class... CancelSignals>
T::T (Interface::NonblockingInputStream::T & input_stream,
    CancelSignals &... cancel_signals) :
    input_stream (input_stream),
    cancel_signals{cancel_signals...},
    start (0),
    end (0)
{
}

T::T (Interface::NonblockingInputStream::T & input_stream,
    std::initializer_list<std::reference_wrapper<Interface::Watchable::T>>
        cancel_signals) :
    input_stream (input_stream),
    cancel_signals (cancel_signals),
    start (0),
    end (0)
{
}
