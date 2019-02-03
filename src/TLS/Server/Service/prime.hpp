void
T::prime ()
{
	this->shutdown_scope = SuppressingScope<Shutdown::Signal::T> (
	    this->shutdown_signal, this->exception_store);
}
