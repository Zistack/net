void
T::store (const Throwable::T & e)
{
	Throwable::T * exception = e.clone ();

	if (!std::atomic_compare_exchange_strong<Throwable::T *> (
	        &this->exception, NULL, exception))
	{
		delete exception;
	}
}
