void
T::prime ()
{
	this->shutdown_scope =
	    SuppressingScope::T<decltype (this->shutdown_signal)> (
	        this->shutdown_signal, this->exception_store);
}