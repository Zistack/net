void
T::clear ()
{
	Throwable::T * e =
	    std::atomic_exchange<Throwable::T *> (&this->exception, NULL);

	if (e) delete e;
}
