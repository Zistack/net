T::T (Signal::T & signal, Failure::ExceptionStore::T * exception_store) :
    signal (signal),
    exception_store (exception_store)
{
	this->signal.set ();
}
