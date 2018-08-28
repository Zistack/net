void
T::poll ()
{
	Throwable::T * e = std::atomic_load<Throwable::T *> (&this->exception);

	if (e) throw *e;
}
