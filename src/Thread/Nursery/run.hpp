template <class Function>
void
T::run (Function && function, Failure::Cancellable::T * cancellable) noexcept
{
	if (this->start (nullptr, cancellable))
	{
		bool first_fail = this->exception_store.tryStore (function);
		this->finish ();
		if (first_fail) this->cancel ();
	}
}
