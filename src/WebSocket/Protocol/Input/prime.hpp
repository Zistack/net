void
T::prime ()
{
	this -> input_shutdown_scope = SuppressingScope::T <Shutdown::Signal::T> (this -> input_shutdown_signal, this -> exception_store);
}
