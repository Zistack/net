template <typename Stream, typename CancelSignal>
void
wait (Stream && stream, CancelSignal && cancel_signal);

template <typename Stream>
void
wait (Stream && stream);
