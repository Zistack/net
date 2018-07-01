void
T::clear ()
{
	Throwable::T * exception =
	    std::atomic_exchange<Throwable::T *> (&this->exception, NULL);

	if (exception) delete exception;
}
