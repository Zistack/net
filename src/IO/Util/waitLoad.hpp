template <class CancelSignal>
void
waitLoad (CancelSignal && cancel_signal, pollfd * fds, int & i)
{
	fds[i] = {.fd = cancel_signal.fileDescriptor (),
	    .events = cancel_signal.events (),
	    .revents = 0};
	++i;
}
