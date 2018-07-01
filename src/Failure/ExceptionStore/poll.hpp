void
T::poll ()
{
	Throwable::T * exception =
	    std::atomic_load<Throwable::T *> (&this->exception);

	if (exception) throw *exception;
}
