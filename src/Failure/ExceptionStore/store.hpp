void
T::store (const Throwable::T & e)
{
	Throwable::T * clone_of_e = e.clone ();
	Throwable::T * expected_value = NULL;

	if (!std::atomic_compare_exchange_strong<Throwable::T *> (
	        &this->exception, &expected_value, clone_of_e))
	{
		delete clone_of_e;
	}
}
