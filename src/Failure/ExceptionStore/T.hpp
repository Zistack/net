T::T ()
{
	std::atomic_init<Throwable::T *> (&this->exception, NULL);
}
